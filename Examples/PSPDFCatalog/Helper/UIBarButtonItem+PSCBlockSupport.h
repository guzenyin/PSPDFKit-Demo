//
//  UIBarButtonItem+PSCBlockSupport.h
//  PSPDFCatalog
//
//  Copyright (c) 2012-2015 PSPDFKit GmbH. All rights reserved.
//
//  The PSPDFKit Sample applications are licensed with a modified BSD license.
//  Please see License for details. This notice may not be removed from this file.
//

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (PSCBlockSupport)

// Simple block-based API for `UIBarButtonItem`.
- (instancetype)initWithTitle:(NSString *)title style:(UIBarButtonItemStyle)style block:(void (^)(id sender))block;

@end

extern void (^PSCTargetActionBlock(id target, SEL action))(id);