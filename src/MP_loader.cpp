/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

// From SC
void SC_AddRecycledItemsScripts();
void SC_AddSC_npcRecycleBot();

// Add all
// cf. the naming convention https://github.com/azerothcore/azerothcore-wotlk/blob/master/doc/changelog/master.md#how-to-upgrade-4
// additionally replace all '-' in the module folder name with '_' here
void AddRecycledItemsScripts()
{
    SC_AddRecycledItemsScripts();
    SC_npcRecycleBot();
}


