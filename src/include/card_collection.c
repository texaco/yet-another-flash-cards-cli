#include "card_collection.h"

#include <stdlib.h>
#include "card_model.h"

/* #something */
CardCollection* createCardCollection(){
	CardCollection* tmp = (CardCollection*)malloc(sizeof(CardCollection));
	/* tambien se puede hacer asi sin incluir ninguna tarjeta en principio */
	/* tmp->data = NULL; */
	
	(*tmp).data = *((Card*)calloc(sizeof(Card), 1));
	(*tmp).data.id = 0;
	(*tmp).data.name = "";
	(*tmp).data.content = "";
	(*tmp).next = NULL;
	return tmp;
}

void destroyCardCollection(CardCollection* collection){
	
	/*   Explicacion grafica */

	/*   paso 1: */
  
	/*   |cabeza| -> |1| -> |2| -> |3| -> NULL */
	/*               ^      */
	/*               |      */
	/*               ptr    */

	/*   paso 2: */

	/*   Se libera ptr (|1|) manteniendo la referencia a next para que no se pierda con aux */
	/*   y se asigna a ptr lo que era ptr en el paso 1 */
	/*   |1| -> |2| -> |3| -> NULL */
	/*   ^      ^ */
	/*   |      | */
	/*   ptr    aux */

	/*   |2| -> |3| -> NULL */
	/*   ^      ^ */
	/*   |      | */
	/*   ptr    aux */
	

	/*   Se repite 2 y 3 hasta que ptr sea NULL, en ese caso ya hemos terminado  y luego se elimina cabecera*/
	
	
	void* ptr,aux;
	
	if((collection*)ptr->next != NULL){
		ptr = (Card*)collection->next;
		while (ptr != NULL){
			aux = (Card*)ptr->next;
			free((Card*)ptr); // free no acepta punteros void, debe tener un tamaño que liberar y void no lo dice
			ptr = aux;
		}
		free(collection); // finalmente liberamos la memoria del contenedor de tarjetas
	}else{
		free(collection);
	}
	/* free(collection); // mal */
	/* en ese caso lo que haces es vaciar la memoria del puntero pero los next no se liberan */
	
}
