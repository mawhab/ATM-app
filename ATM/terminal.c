#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	printf("Please enter transaction date (dd/mm/yyyy): ");
	fgets(termData->transactionDate, 10, stdin);
	
	int len = strlen(termData->transactionDate);

	if (len != 10) return WRONG_DATE;

	return OK_T;
}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData) {
	int res = getOlder(parseDate(termData.transactionDate), parseDate(cardData.cardExpirationDate));
	if (res == 1) return OK_T;
	
	return EXPIRED_CARD;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	printf("Please enter transaction amount: ");
	scanf_s("%f", &termData->transAmount, 4);

	if (termData->transAmount <= 0) return INVALID_AMOUNT;

	return OK_T;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) {
	printf("Please enter max transaction amount: ");
	scanf_s("%f", &termData->maxTransAmount, 4);

	if (termData->maxTransAmount <= 0) return INVALID_MAX_AMOUNT;

	return OK_T;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
	if (termData->transAmount <= termData->maxTransAmount) return OK_T;
	
	return EXCEED_MAX_AMOUNT;
}

