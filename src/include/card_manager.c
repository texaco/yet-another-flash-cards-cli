#include "card_manager.h"

#include <stdlib.h>
#include <string.h>
#include "card_model.h"
#include "card_collection.h"

#if 0
Card addNewCard(CardCollection** collection, unsigned int id, char* name, char* content){
  CardCollection* newNode = createCardCollection();
  (*newNode).data.id = id;
  (*newNode).data.name = name;
  (*newNode).data.content = content;
  (*newNode).next = *collection;
  *collection = newNode;

  return (*newNode).data;
}
#endif

/* In this method I've used the linked list structure to add a new Card at the end of the */
/* collection using the next pointer while it is not NULL */

Card addNewCard(CardCollection* collection, Card new_card){
	/* avanzamos hasta el final (donde esta el NULL) */
	if (collection->next != NULL){
		void* ptr;
		ptr = collection->next;
		while(ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = (void*)malloc(sizeof(new_card));
		*((Card*)(collection->next)) = new_card;
	}else{
		/* in this case, the register is empty, then we are going to insert it in the */
		collection->next = (void*)malloc(sizeof(new_card));
		*((Card*)(collection->next)) = new_card;
	}
	return new_card;
}

/* Search for a given node by ID. If it find the node it will return a
 2 possitions array.

 getNodeAndPreviousByID[0] is the previous node.
 getNodeAndPreviousByID[1] is the node that match with searched ID.
 Since the collection structure cannot be walked in 2 directions, this
 is useful to perform operations like removing a node.

 The function is not declared on the header file since it is meant to
 be used only internally.

If the ID is the first node, the previous node is NULL.  Whereas if
the ID is not to be found in the collection both array possitions are
settled as NULL.*/
CardCollection** getNodeAndPreviousByID(CardCollection* collection, unsigned int id){
  CardCollection* NOT_FOUND[] = {NULL, NULL};
  CardCollection* pivot[2] = {NULL, collection};
  unsigned int found = 0;
  while((*pivot[1]).next != NULL && !found){
    found = (*pivot[1]).data.id == id;
    pivot[0] = found ? pivot[0] : pivot[1];
    pivot[1] = found ? pivot[1]: (CardCollection*)(*(pivot[1])).next;
  }

  return found ? pivot : NOT_FOUND;
}

Card* getCardById(CardCollection* collection, unsigned int id){
  CardCollection* node = getNodeAndPreviousByID(collection, id)[1];
  if(node == NULL){
    return NULL;
  }

  return &((*node).data);
}

void destroyCardById(CardCollection** collectionPointer, unsigned int id){
  CardCollection** nodes = getNodeAndPreviousByID(*collectionPointer, id);

  if(nodes[1] == NULL){
    return;
  }

  if(nodes[0] == NULL){
    /* It is the first node, so we need to move collecionPointer and
       free the first node. */
    CardCollection* tmp = *collectionPointer;
    *collectionPointer = (CardCollection*)(**collectionPointer).next;
    destroyCardCollection(tmp);
    return;
  }

  /* It is some intermediary node. Moves previous node next to node
     next and then destroy node. */

  (*nodes[0]).next = (*nodes[1]).next;
  destroyCardCollection(nodes[1]);
}
