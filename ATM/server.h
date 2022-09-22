#ifndef SERVER_H
#define SERVER_H
#include "terminal.h"

typedef struct ST_transaction
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState;
	uint32_t transactionSequenceNumber;
} ST_transaction_t;

typedef enum EN_transState
{
	APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef enum EN_serverError
{
	OK_S, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t;

typedef struct ST_accountsDB
{
	float balance;
	uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

ST_accountsDB_t accounts_DB[255] = { {50.0,"8359767489631518994"},
									 {102.5,"7650992247541229299"},
									 {20.2,"2025829120202598386"} };


ST_transaction_t transactions_DB[255];

ST_accountsDB_t* found = NULL;


EN_transState_t recieveTransactionData(ST_transaction_t* transData);

EN_serverError_t isValidAccount(ST_cardData_t* cardData);

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData);

EN_serverError_t saveTransaction(ST_transaction_t* transData);

//EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData);

#endif