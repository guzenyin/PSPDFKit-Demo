//
//  PSPDFLineHelper.h
//  PSPDFKit
//
//  Copyright (c) 2013-2014 PSPDFKit GmbH. All rights reserved.
//
//  THIS SOURCE CODE AND ANY ACCOMPANYING DOCUMENTATION ARE PROTECTED BY INTERNATIONAL COPYRIGHT LAW
//  AND MAY NOT BE RESOLD OR REDISTRIBUTED. USAGE IS BOUND TO THE PSPDFKIT LICENSE AGREEMENT.
//  UNAUTHORIZED REPRODUCTION OR DISTRIBUTION IS SUBJECT TO CIVIL AND CRIMINAL PENALTIES.
//  This notice may not be removed from this file.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import "PSPDFAnnotation.h"
#import "PSPDFMacros.h"

PSPDFKIT_EXTERN_C_BEGIN

#define PSPDFAllLineEndsAreInside   1                   // Define to 1 to keep all line endings extruding from the line/polyline coordinates to a minimum
                                                        // (i.e. reverse arrow line ends are kept from jutting out past the line/polyline endpoints).
                                                        // The PDF spec is conveniently unclear on this topic, do what is most appealing visually, but
                                                        // since every other line ending is kept inside the endpoints, this is enabled here for consistency.
#define PSPDFPolyJoinStyle          kCGLineJoinMiter    // Or kCGLineJoinBevel
#define PSPDFMiterLimit             10.f                // Avoid miters turning to bevels by supplying a high miter limit

typedef NS_ENUM(NSInteger, PSPDFLineEndType) {
    PSPDFLineEndTypeNone,
    PSPDFLineEndTypeSquare,
    PSPDFLineEndTypeCircle,
    PSPDFLineEndTypeDiamond,
    PSPDFLineEndTypeOpenArrow,
    PSPDFLineEndTypeClosedArrow,
    PSPDFLineEndTypeButt,
    PSPDFLineEndTypeReverseOpenArrow,
    PSPDFLineEndTypeReverseClosedArrow,
    PSPDFLineEndTypeSlash
};

CF_IMPLICIT_BRIDGING_ENABLED

// Constructs a polyline between all given points. The two ends of this line can have a `PSPDFLineEndType`.
extern void PSPDFConstructPolyLine(const CGPoint *points, NSUInteger pointsCount, PSPDFLineEndType lineEnd1, PSPDFLineEndType lineEnd2, CGFloat lineWidth,
                                   CGPathRef *storedLinePath, CGPathRef *storedLineEnd1FillPath, CGPathRef *storedLineEnd1StrokePath, CGPathRef *storedLineEnd2FillPath, CGPathRef *storedLineEnd2StrokePath,
                                   BOOL originUpperLeft);

// Constructs a polyline, convenience method that uses `PSPDFConstructPolyLine` internally.
extern void PSPDFConstructPolyLineBezierPathWithPoints(NSArray *points, PSPDFLineEndType lineEnd1, PSPDFLineEndType lineEnd2, CGFloat lineWidth, BOOL originUpperLeft, UIBezierPath **outStrokePath, UIBezierPath **outFillPath);

// Draws a polyline between all given points. The two ends of this line can have a PSPDFLineEndType.
extern void PSPDFDrawPolyLine(CGContextRef context, const CGPoint *points, NSUInteger pointsCount, PSPDFLineEndType lineEnd1, PSPDFLineEndType lineEnd2, CGFloat lineWidth);

// Draws a line between two points with the specified line end types.
extern void PSPDFDrawLine(CGContextRef context, CGPoint point1, CGPoint point2, PSPDFLineEndType lineEnd1, PSPDFLineEndType lineEnd2, CGFloat lineWidth);

// Returns whether the line end type requires a full line.
// A full line is required if the line end type directly "connects" to the line, e.g. for an open arrow.
extern BOOL PSPDFLineEndNeedsFullLine(PSPDFLineEndType lineEnd);

// Returns the fill and stroke paths corresponding to a given line end type.
extern void PSPDFCreatePathsForLineEndType(PSPDFLineEndType endType, const CGPoint *points, NSUInteger pointsCount, CGFloat lineWidth, CGPathRef *storedFillPath, CGPathRef *storedStrokePath);

// Returns the rectangle encompassing the line end at the first of two points.
extern CGRect PSPDFGetLineEndRectangle(CGPoint point1, CGPoint point2, PSPDFLineEndType lineEnd, CGFloat lineWidth);

// Transforms line end string <-> line end type (PDF reference).
extern NSString * const PSPDFLineEndTypeTransformerName;

// Will update `lineCap` and `lineJoin` depending on the `annotationType` set.
extern void PSPDFUpdateShapeLayerLineStyleForAnnotationType(CAShapeLayer *shapeLayer, PSPDFAnnotationType annotationType);

// Converts the `dashArray` of an annotation into the array usage in CoreGraphics.
// @note We work around an analyzer issue that would produce false positives if we use PSPDFCreate* as name instead of Allocate.
extern CGFloat *PSPDFAllocateLineDashArrayForAnnotation(PSPDFAnnotation *annotation, NSUInteger *outDashCount);

// Returns perimeter for a given polygon.
extern CGFloat PSPDFPolygonPerimeter(const CGPoint *points, NSUInteger pointsCount);

// Returns distance between given points.
extern CGFloat PSPDFDistanceBetweenPoints(CGPoint p1, CGPoint p2);

// Return YES if points for the polygon is given in clockwise direction, otherwise returns NO.
extern BOOL PSPDFPolygonPathIsClockwise(const CGPoint *points, NSUInteger pointsCount);

// Returns polygon path with a "cloudy" border effect applied
extern CGMutablePathRef PSPDFCreateCloudyPathForPolygon(const CGPoint *points, NSUInteger pointsCount, CGFloat intensity);

// Returns polygon path
extern CGPathRef PSPDFCreatePathForPolygon(const CGPoint *points, NSUInteger pointsCount);

// Returns path for a given rect with a "cloudy" border effect
extern CGPathRef PSPDFCreateCloudyPathForRect(CGRect rect, CGFloat intensity);

// Returns path with a "cloudy" border effect bound by a given rect
extern CGPathRef PSPDFCreateCloudyPathBoundByRect(CGRect rect, CGFloat intensity);

// Return an ellipse path with a "cloudy" border effect bound by a given rect
extern CGPathRef PSPDFCreateCloudyPathForEllipse(CGRect rect, CGFloat intensity);

CF_IMPLICIT_BRIDGING_DISABLED

PSPDFKIT_EXTERN_C_END
