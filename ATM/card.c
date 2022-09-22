#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	printf("Please enter card holder name: ");
	fgets(cardData->cardHolderName, 40, stdin);
	int len = strlen(cardData->cardHolderName);
	if (len < 20 || len>24) return WRONG_NAME;
	
	return OK_C;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	printf("Please enter card PAN: ");
	fgets(cardData->primaryAccountNumber, 19, stdin);

	int len = strlen(cardData->primaryAccountNumber);

	if (len > 19 || len < 16) return WRONG_PAN;
	
	return OK_C;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	printf("Please enter card expiry date (mm/yy): ");
	fgets(cardData->cardExpirationDate, 5, stdin);
	
	int len = strlen(cardData->cardExpirationDate);

	if (len == 5) return OK_C;

	return WRONG_EXP_DATE;
}