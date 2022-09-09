#include "HashQuad.h"
#include <stdlib.h>
#include <stdio.h>

HashTable InitHashTable(int Tablesize)
{
    HashTable H = malloc(sizeof(struct HashTb1));

    H->Tablesize = Tablesize;
    H->TheCell = malloc(sizeof(Cell)*H->Tablesize);

    for(int i = 0; i < H->Tablesize; i++)
      H->TheCell[i].Info = Empty;

    return H;
}
// Key is string usually,but for test easily , I use int
HashIndex Hash(HashElementType Key, int Tablesize)
{
    return Key % Tablesize;
}

HashIndex Hash2(HashElementType X)
{
    return R - (X % R);
}
// F(i) = i*i and F(i) = F(i-1) + 2i -1 equally
// the function is find empty cell
HashPosition FindSquare(HashElementType Key, HashTable H)
{
    HashPosition CurrentPos;
    int CollisionNum = 0;
    int count = 0;

    CurrentPos = Hash(Key, H->Tablesize);
    while(H->TheCell[CurrentPos].Info != Empty &&
          H->TheCell[CurrentPos].Element != Key)
    {
        CurrentPos += 2 * ++CollisionNum -1;
        if(CurrentPos>=H->Tablesize)
           CurrentPos -= H->Tablesize;
        printf("FindSquare: %d\n", count);
    }
    return CurrentPos;
}
// F(i) = i.
// the function is find empty cell.
HashPosition FindLinear(HashElementType Key, HashTable H)
{
    HashPosition CurrentPos;
    int CollisionNum = 0;
    int count = 0;

    CurrentPos = Hash(Key, H->Tablesize);
    while(H->TheCell[CurrentPos].Info != Empty &&
          H->TheCell[CurrentPos].Element != Key)
    {
        CurrentPos += 1;
        if(CurrentPos>=H->Tablesize)
           CurrentPos -= H->Tablesize;
        
        printf("FindLinear: %d\n", count);
    }
    return CurrentPos; 
}
// F(i) = i*Hash2(X).
// the function is find empty cell.
HashPosition FindDoubleHash(HashElementType Key, HashTable H)
{
    HashPosition CurrentPos;
    int CollisionNum = 0;
    int count = 0;

    CurrentPos = Hash(Key, H->Tablesize);
    while(H->TheCell[CurrentPos].Info != Empty &&
          H->TheCell[CurrentPos].Element != Key)
    {
        CurrentPos = ++CollisionNum * Hash2(Key);
        if(CurrentPos>=H->Tablesize)
           CurrentPos -= H->Tablesize;
        printf("FindDoubleHash: %d",count);
    }
    return CurrentPos; 
}
// InsertOfEntry have three types(Linear、Square、DoubleHash).
void HashInsert(HashElementType Key, HashTable H, enum InsertOfEntry Type)
{
    HashPosition Pos;
    switch (Type)
    {
    case Linear: Pos = FindLinear(Key, H);
        break;
    case Square: Pos = FindSquare(Key, H);
        break;
    case DoubleHash: Pos = FindDoubleHash(Key, H);
    default:
        break;
    }
    if(H->TheCell[Pos].Info != Legitmate)
    {
        H->TheCell[Pos].Info = Legitmate;
        H->TheCell[Pos].Element = Key;
    }
}
// 
HashTable HashDestory(HashTable H)
{
	free(H->TheCell);
	free(H);
    return NULL;
}