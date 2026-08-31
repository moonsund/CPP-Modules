#include "Account.hpp"

int Account::_nb_accounts = 0;
int Account::_total_amount = 0;
int Account::_total_nb_deposits = 0;
int Account::_total_nb_withdrawals = 0;

Account::Account(int initial_deposit)
{
    ++_nb_accounts;
    _total_amount += initial_deposit;
}