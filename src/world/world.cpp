#include "data/data-world.h"

#include "areas/big-tree.h"
#include "areas/cave01.h"
#include "areas/grove-house.h"
#include "areas/grove01.h"
#include "areas/grove04.h"
#include "areas/grove06.h"
#include "areas/secret-room.h"
#include "tiles/log.h"
#include "util/hashtable.h"
#include "util/string.h"

static Hashmap<String, DataArea*> areas;

StringView dataWorldName = "Testing World";
StringView dataWorldAuthor = "Michael Reiley and Paul Merrill";
StringView dataWorldVersion = "1";

enum MoveMode dataWorldMoveMode = MoveMode::TILE;
fvec2 dataWorldViewportResolution = {240, 160};
int dataWorldInputPersistDelayInitial = 300;
int dataWorldInputPersistDelayConsecutive = 100;
StringView dataWorldStartArea = "areas/grove01.json";
StringView dataWorldPlayerFile = "entities/player/player.json";
StringView dataWorldPlayerStartPhase = "down";
vicoord dataWorldStartCoords = {15, 22, 0.0};

StringView dataWorldDatafile = "./testing.world";

bool
dataWorldInit() noexcept {
    areas["areas/basement.json"] = new DataArea;  // no special logic
    areas["areas/bigtree.json"] = new BigTreeArea;
    areas["areas/cave01.json"] = new Cave01;
    areas["areas/grove_house.json"] = new GroveHouse;
    areas["areas/grove01.json"] = new Grove01;
    areas["areas/grove04.json"] = new Grove04;
    areas["areas/grove06.json"] = new Grove06;
    areas["areas/secret_room.json"] = new SecretRoom;
    logInfo("TestingDataWorld", "Ready to go");
    return true;
}

DataArea*
dataWorldArea(StringView areaName) noexcept {
    return areas[areaName];
}
