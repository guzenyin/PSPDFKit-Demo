//
//  PSCMergeDocumentsViewController.h
//  PSPDFCatalog
//
//  Copyright (c) 2012-2015 PSPDFKit GmbH. All rights reserved.
//
//  The PSPDFKit Sample applications are licensed with a modified BSD license.
//  Please see License for details. This notice may not be removed from this file.
//

#import <UIKit/UIKit.h>

// Simple variant of a document merge UI to get you started.
@interface PSCMergeDocumentsViewController : UIViewController

// Initialize with two documents, show them side-by-side
- (instancetype)initWithLeftDocument:(PSPDFDocument *)leftDocument rightDocument:(PSPDFDocument *)rightDocument NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) PSPDFDocument *leftDocument;
@property (nonatomic, strong, readonly) PSPDFDocument *rightDocument;

@end
