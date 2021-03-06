#include "EPSG4326.h"
#include "utils/Const.h"
#include "utils/Log.h"

#include <cmath>

namespace carto {

    EPSG4326::EPSG4326() :
        Projection(MapBounds(MapPos(-180.0, -90.0), MapPos(180.0, 90.0)))
    {
    }
    
    EPSG4326::~EPSG4326() {
    }
        
    MapPos EPSG4326::fromInternal(const MapPos& mapPosInternal) const {
        double x = mapPosInternal.getX() / UNITS_TO_INTERNAL * Const::RAD_TO_DEG;
        double y = 90.0 - Const::RAD_TO_DEG * (2.0 * std::atan(std::exp(-mapPosInternal.getY() / UNITS_TO_INTERNAL)));
        double z = mapPosInternal.getZ() / UNITS_TO_INTERNAL * EARTH_RADIUS;
        return MapPos(x, y, z);
    }
    
    MapPos EPSG4326::toInternal(const MapPos& mapPos) const {
        double x = mapPos.getX() * UNITS_TO_INTERNAL * Const::DEG_TO_RAD;
        double a = std::sin(mapPos.getY() * Const::DEG_TO_RAD);
        double y = 0.5 * UNITS_TO_INTERNAL * std::log((1.0 + a) / (1.0 - a));
        double z = mapPos.getZ() * UNITS_TO_INTERNAL / EARTH_RADIUS;
        return MapPos(x, y, z);
    }

    MapPos EPSG4326::fromWgs84(const MapPos& wgs84Pos) const {
        return wgs84Pos;
    }
    
    MapPos EPSG4326::toWgs84(const MapPos& mapPos) const {
        return mapPos;
    }
    
    std::string EPSG4326::getName() const {
        return "EPSG:4326";
    }

    const double EPSG4326::EARTH_RADIUS = 6378137.0;
        
    const double EPSG4326::UNITS_TO_INTERNAL = Const::WORLD_SIZE / (2.0 * Const::PI);
    
}
