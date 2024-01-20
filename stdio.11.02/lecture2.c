#include <stdio.h>
#include <stdlib.h>

struct Item {
    int Id;
    int   Level;
};

struct Item* MakeItem(int Id, int Level) {
    struct Item* NewItem = (struct Item*)malloc(sizeof(struct Item));
    NewItem->Id = Id;
    NewItem->Level = Level;

    return NewItem;
}

int IsGoodItem(struct Item* Item) {
    if (Item->Level >= 2) return 1;
    return 0;
}

int IsLowIdItem(struct Item* Item) {
    if (Item->Id <= 2) return 1;
    return 0;
}

void FindItemByPredicate(struct Item** Items, int SizeOfItem, int(*Predicate)(struct Item*)) {
    for (int i = 0; i < SizeOfItem; i++) {
        if (Predicate(Items[i])) {
            printf("find Item! id : %d, Level : %d\n", Items[i]->Id, Items[i]->Level);
        }
    }
}

int main()
{
    struct Item* Items[4] = {
       MakeItem(1,0),
       MakeItem(3,1),
       MakeItem(2,2),
       MakeItem(4,3)
    };

    FindItemByPredicate(Items, 4, IsGoodItem);
    FindItemByPredicate(Items, 4, IsLowIdItem);

    for (int i = 0; i < 4; i++) {
        free(Items[i]);
    }

    return 0;
}