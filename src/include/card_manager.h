#ifndef __CARD_MANAGER_H__
#define __CARD_MANAGER_H__

#include "card_model.h"
#include "card_collection.h"

/* Add new card to a given collection. */
Card addNewCard(CardCollection** collection, unsigned int id, char* name, char* content);

/* Get a card pointer by ID. */
Card* getCardById(CardCollection* collection, unsigned int id);

/* Delete a card from collection by ID. */
void destroyCardById(CardCollection** collection, unsigned int id);
#endif
