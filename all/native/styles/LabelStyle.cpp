#include "LabelStyle.h"

namespace carto {

    LabelStyle::LabelStyle(const Color& color,
                           float attachAnchorPointX,
                           float attachAnchorPointY,
                           bool causesOverlap,
                           bool hideIfOverlapped,
                           float horizontalOffset,
                           float verticalOffset,
                           int placementPriority,
                           bool scaleWithDPI,
                           const std::shared_ptr<AnimationStyle>& animStyle,
                           float anchorPointX,
                           float anchorPointY,
                           bool flippable,
                           BillboardOrientation::BillboardOrientation orientationMode,
                           BillboardScaling::BillboardScaling scalingMode,
                           float renderScale) :
        BillboardStyle(color,
                       attachAnchorPointX,
                       attachAnchorPointY,
                       causesOverlap,
                       hideIfOverlapped,
                       horizontalOffset,
                       verticalOffset,
                       placementPriority,
                       scaleWithDPI,
                       animStyle),
        _anchorPointX(anchorPointX),
        _anchorPointY(anchorPointY),
        _flippable(flippable),
        _orientationMode(orientationMode),
        _scalingMode(scalingMode),
        _renderScale(renderScale)
    {
    }
    
    LabelStyle::~LabelStyle() {
    }
        
    float LabelStyle::getAnchorPointX() const {
        return _anchorPointX;
    }
    
    float LabelStyle::getAnchorPointY() const {
        return _anchorPointY;
    }
    
    bool LabelStyle::isFlippable() const {
        return _flippable;
    }
    
    BillboardOrientation::BillboardOrientation LabelStyle::getOrientationMode() const {
        return _orientationMode;
    }
    
    BillboardScaling::BillboardScaling LabelStyle::getScalingMode() const {
        return _scalingMode;
    }

    float LabelStyle::getRenderScale() const {
        return _renderScale;
    }
    
}
