//
//  PSPDFBlurView.h
//  PSPDFKit
//
//  Copyright (c) 2014 PSPDFKit GmbH. All rights reserved.
//
//  THIS SOURCE CODE AND ANY ACCOMPANYING DOCUMENTATION ARE PROTECTED BY INTERNATIONAL COPYRIGHT LAW
//  AND MAY NOT BE RESOLD OR REDISTRIBUTED. USAGE IS BOUND TO THE PSPDFKIT LICENSE AGREEMENT.
//  UNAUTHORIZED REPRODUCTION OR DISTRIBUTION IS SUBJECT TO CIVIL AND CRIMINAL PENALTIES.
//  This notice may not be removed from this file.
//

#import <UIKit/UIKit.h>

/// `PSPDFBlurView` allows you to get a blurred background, just like it is used in many cases on iOS 7.
@interface PSPDFBlurView : UIView

/// Controls if bluring is enabled.
@property (nonatomic, assign, getter = isBlurEnabled) BOOL blurEnabled;

/// Everything from the `renderView` up the view hierarchy to this view is used to render the
/// background. Defaults to the view's `superview`.
@property (nonatomic, weak) UIView *renderView;

/// The `containerView` is hidden before rendering the background. This is useful because
/// you usually only want to blur the views below a given view. Defaults to the view itself.
@property (nonatomic, weak) UIView *containerView;

/// Wrapper for the `blurEnabled` property since UIAppearance can only handle object values.
@property (nonatomic, strong) NSNumber *blurEnabledObject UI_APPEARANCE_SELECTOR;

/// The frame interval used for the underlaying `CADisplayLink`. Defaults to `5`.
@property (nonatomic, assign) NSUInteger frameInterval;

@end