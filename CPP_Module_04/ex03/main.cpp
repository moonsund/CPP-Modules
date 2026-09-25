#include <cassert>
#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// checks the same types of materias, but with different addresses.
static void checkCharacterCopy(const Character& original,
                               const Character& copy)
{
    assert(original.getName() == copy.getName());

    for (int i = 0; i < 4; ++i)
    {
        AMateria* a = original.getMateriaAddress(i);
        AMateria* b = copy.getMateriaAddress(i);

        if (a == 0)
        {
            assert(b == 0);
        }
        else
        {
            assert(b != 0);
            assert(a != b);
            assert(a->getType() == b->getType());
        }
    }
}

int main()
{
    std::cout << "\n--- Source: empty and full ---\n";

    MateriaSource source; // MateriaSource was created

    assert(source.createMateria("ice") == 0); // Unknown materia type: ice
    source.learnMateria(0); // Null pointer ignored

    AMateria* iceSample = new Ice; // Materia ice was created
    source.learnMateria(iceSample); // Materia ice stored in slot # 0
    source.learnMateria(iceSample); // Pointer already stored in slot 0; ignored

    source.learnMateria(new Cure); // Materia cure was created; Materia cure stored in slot # 1
    source.learnMateria(new Ice);   // Materia ice was created; Materia ice stored in slot # 2
    source.learnMateria(new Cure);  // Materia cure was created; Materia cure stored in slot # 3

    source.learnMateria(iceSample); // Pointer already stored in slot 0; ignored
    source.learnMateria(new Ice);  // Materia ice was created; Storage full; deleting incoming materia: ice

    assert(source.createMateria("unknown") == 0); // Unknown materia type: unknown

    AMateria* iceA = source.createMateria("ice"); // Materia cloned: ice
    AMateria* iceB = source.createMateria("ice"); // Materia cloned: ice
    AMateria* cure = source.createMateria("cure"); // Materia cloned: cure

    assert(iceA != 0 && iceB != 0 && cure != 0);
    assert(iceA != iceB);
    assert(iceA != iceSample);
    assert(iceA->getType() == "ice");
    assert(cure->getType() == "cure");

    delete iceA;
    delete iceB;
    delete cure;

    std::cout << "\n--- Character: equip, use, unequip ---\n";

    Character hero("hero"); // Character hero was created
    Character target("target"); // Character target was created

    hero.equip(0); // Null pointer ignored
    hero.use(0, target);
    hero.use(-1, target);
    hero.use(4, target);
    hero.unequip(-1);
    hero.unequip(4);
    hero.unequip(0);

    assert(hero.getMateriaAddress(-1) == 0);
    assert(hero.getMateriaAddress(4) == 0);

    AMateria* first = source.createMateria("ice"); // Materia cloned: ice
    hero.equip(first); // Materia ice stored in slot # 0
    hero.equip(first); // Pointer already stored in slot 0; ignored

    assert(hero.getMateriaAddress(0) == first);
    assert(hero.getMateriaAddress(1) == 0);

    hero.equip(source.createMateria("cure")); // Materia cloned: cure; Materia cure stored in slot # 1
    hero.equip(source.createMateria("ice")); // Materia cloned: ice; Materia ice stored in slot # 2
    hero.equip(source.createMateria("cure")); // Materia cloned: cure; Materia cure stored in slot # 3

    for (int i = 0; i < 4; ++i)
        assert(hero.getMateriaAddress(i) != 0);

    AMateria* extra = source.createMateria("ice"); // Materia cloned: ice
    hero.equip(extra); // [Character] Inventory full; materia not equipped

    for (int i = 0; i < 4; ++i)
        assert(hero.getMateriaAddress(i) != extra);

    delete extra;

    hero.use(0, target); // * shoots an ice bolt at target *
    hero.use(1, target); // * heals target's wounds *

    AMateria* removed = hero.getMateriaAddress(1);
    hero.unequip(1); // Character unequipped Materia cure from slot # 1

    assert(hero.getMateriaAddress(1) == 0);
    hero.unequip(1);
    hero.use(1, target); // * heals target's wounds *

    removed->use(target);
    delete removed;

   
    hero.equip(hero.getMateriaAddress(2)); // Pointer already stored in slot 2; ignored
    assert(hero.getMateriaAddress(1) == 0);

    AMateria* replacement = source.createMateria("cure"); // Materia cloned: cure
    hero.equip(replacement); // Materia cure stored in slot # 1
    assert(hero.getMateriaAddress(1) == replacement);

    std::cout << "\n--- Character: deep copying ---\n";

    Character assigned("old name"); // Character old name was created
    assigned.equip(source.createMateria("cure")); // Materia cloned: cure; Materia cure stored in slot # 0
    assigned.equip(source.createMateria("ice")); // Materia cloned: ice; Materia ice stored in slot # 1

    Character* copied = 0;

    {
        Character original("original"); // Character original was created
        original.equip(source.createMateria("ice")); // Materia cloned: ice; Materia ice stored in slot # 0
        original.equip(source.createMateria("cure")); // Materia cloned: cure; Materia cure stored in slot # 1
        original.equip(source.createMateria("ice")); // Materia cloned: ice; Materia ice stored in slot # 2

        AMateria* middle = original.getMateriaAddress(1);
        original.unequip(1); // Character unequipped Materia cure from slot # 1
        delete middle;

        copied = new Character(original);
        assigned = original;

        checkCharacterCopy(original, *copied);
        checkCharacterCopy(original, assigned);
        checkCharacterCopy(*copied, assigned);

        Character& same = assigned;
        AMateria* before = assigned.getMateriaAddress(0);
        assigned = same;

        assert(assigned.getMateriaAddress(0) == before);
        checkCharacterCopy(original, assigned);
    }

    copied->use(0, target); // * shoots an ice bolt at target *
    copied->use(2, target); // * shoots an ice bolt at target *
    assigned.use(0, target); // * shoots an ice bolt at target *
    assigned.use(2, target); // * shoots an ice bolt at target *
    delete copied; // Character original destroyed: 2 stored objects deleted

    Character empty("empty"); // Character empty was created
    Character emptyCopy(empty);
    checkCharacterCopy(empty, emptyCopy);

    assigned = empty;
    checkCharacterCopy(empty, assigned);

    std::cout << "\n--- Source: deep copying ---\n";

    MateriaSource assignedSource;
    assignedSource.learnMateria(new Cure);
    assignedSource.learnMateria(new Cure);

    MateriaSource* copiedSource = 0;

    {
        MateriaSource original;
        original.learnMateria(new Ice);

        copiedSource = new MateriaSource(original);
        assignedSource = original;

        MateriaSource& same = assignedSource;
        assignedSource = same;
    }

    AMateria* fromCopy = copiedSource->createMateria("ice");
    AMateria* fromAssignment = assignedSource.createMateria("ice");

    assert(fromCopy != 0 && fromAssignment != 0);
    assert(fromCopy != fromAssignment);
    assert(copiedSource->createMateria("cure") == 0);
    assert(assignedSource.createMateria("cure") == 0);

    fromCopy->use(target);
    fromAssignment->use(target);

    delete fromCopy;
    delete fromAssignment;
    delete copiedSource;

    MateriaSource emptySource;
    MateriaSource emptySourceCopy(emptySource);
    assert(emptySourceCopy.createMateria("ice") == 0);

    assignedSource = emptySource;
    assert(assignedSource.createMateria("ice") == 0);

    std::cout << "\n--- Deletion through interfaces ---\n";

    ICharacter* character = new Character("interface");
    character->equip(new Ice);
    character->use(0, target);
    delete character;

    IMateriaSource* interfaceSource = new MateriaSource;
    interfaceSource->learnMateria(new Cure);

    AMateria* created = interfaceSource->createMateria("cure");
    assert(created != 0);

    delete interfaceSource;
    created->use(target);
    delete created;

    std::cout << "\nAll assertions passed; local objects will now be destroyed.\n";
    return 0;
}