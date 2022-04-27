#ifndef __CARD_COLLECTION_H__
#define __CARD_COLLECTION_H__

#include "card_model.h"

/* comment */
typedef struct CardCollectionModel {
  Card data;
  void* next;
} CardCollection;

/* Creates a card collection */
CardCollection* createCardCollection();

/* Destroy a given card collection */
void destroyCardCollection(CardCollection*);

#endif
