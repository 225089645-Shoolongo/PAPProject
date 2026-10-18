#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct
{
    char assetID[20];
    char assetName[50];
    char assetType[30];
    double purchaseValue;
    char department[50];
    char condition[30];
} Asset;

void assetMenu(void);
void addAsset(void);
void displayAssets(void);
void searchAsset(void);

int getAssetCount(void);
const Asset *getAssetArray(void);

#endif
