#include "server.h"

EN_transState_t recieveTransactionData(ST_transaction_t* transData) {
	EN_serverError_t state = APPROVED;
	if (isValidAccount(&(transData->terminalData)) != OK_S) state = DECLINED_STOLEN_CARD;
	
	else if (isAmountAvailable(&(transData->terminalData)) != OK_S) state = DECLINED_INSUFFECIENT_FUND;

	transData->transState = state;

	if (saveTransaction(transData) != OK_S) state = INTERNAL_SERVER_ERROR;

	if(state == APPROVED) found->balance -= transData->terminalData.transAmount;

	return state;
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	for (int i = 0; i < 255; i++) {
		if (strcmp(cardData->primaryAccountNumber, accounts_DB[i].primaryAccountNumber) == 0) {
			found = &accounts_DB[i];
			return OK_S;
		}
	}

	return DECLINED_STOLEN_CARD;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	if (termData->transAmount > found->balance) return LOW_BALANCE;

	return OK_S;
}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	static int sequence = 0;
	if (sequence > 254) return SAVING_FAILED;
	
	transData->transactionSequenceNumber = sequence;

	transactions_DB[sequence++] = *transData;

	return OK_S;
}
