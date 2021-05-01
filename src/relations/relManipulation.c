#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <header.h>
#include <relations.h>

/**   
 * @brief This function allows to insert a set to parts relation in the relations list, returning the relations list with the new realtion inserted.
 * @param lst ➔ The sets list where the set is going to be inserted
 * @param set_num ➔ The set_num of the set to insert in the relation
 * @param quantity ➔ The quantity of the part to insert in the relation
 * @param part_num ➔ The  of the set to insert
 * @param theme ➔ The theme of the set to insert
 * @return RELATIONS* ➔ relations list with the new insertion
 * @see OpenRelations
 */
RELATIONS *InsertRelation(RELATIONS *lst, char *set_num, int quantity, char *part_num)
{
    assert(set_num);
    assert(part_num);

    RELATIONS *new_relation = malloc(sizeof(RELATIONS));

    strcpy(new_relation->set_num, set_num);
    strcpy(new_relation->part_num, part_num);
    new_relation->quantity = quantity;

    if (lst)
        new_relation->next = lst;
    else
        new_relation->next = NULL;

    if (new_relation->next)
        new_relation->next->previous = new_relation;

    new_relation->previous = NULL;
    return new_relation;
}
