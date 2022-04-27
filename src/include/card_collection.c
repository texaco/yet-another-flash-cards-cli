#include "card_collection.h"

#include <stdlib.h>
#include "card_model.h"

/* #something */
CardCollection* createCardCollection(){
  /* To be implemented */
  CardCollection* tmp = (CardCollection*)malloc(sizeof(CardCollection));
  (*tmp).data = *((Card*)calloc(sizeof(Card), 1));
  (*tmp).data.id = 0;
  (*tmp).data.name = "";
  (*tmp).data.content = "";
  (*tmp).next = NULL;
  return tmp;
}

void destroyCardCollection(CardCollection* collection){
  free(collection);
  collection = NULL;
}
