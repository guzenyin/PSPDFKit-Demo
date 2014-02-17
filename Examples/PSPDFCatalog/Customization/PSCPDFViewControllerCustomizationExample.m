//
//  PSCPDFViewControllerCustomizationExample.m
//  PSPDFCatalog
//
//  Copyright (c) 2011-2014 PSPDFKit GmbH. All rights reserved.
//
//  The PSPDFKit Sample applications are licensed with a modified BSD license.
//  Please see License for details. This notice may not be removed from this file.
//

#import "PSCPDFViewControllerCustomizationExample.h"
#import "PSCAssetLoader.h"
#import "PSCEmbeddedTestController.h"
#import "PSCChildViewController.h"
#import "PSCButtonPDFViewController.h"
#import "PSCImageOverlayPDFViewController.h"
#import "PSCCustomBookmarkBarButtonItem.h"
#import "PSCCustomToolbarController.h"
#import "PSCTintablePDFViewController.h"
#import "PSCAppearancePDFViewController.h"
#import <UIKit/UIViewController.h>

@implementation PSCPDFViewControllerCustomizationUsingaNIBExample

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - PSCExample

- (id)init {
    if (self = [super init]) {
        self.title = @"Using a NIB";
        self.category = PSCExampleCategoryPSPDFViewControllerCustomization;
        self.priority = 20;
    }
    return self;
}

- (UIViewController *)invokeWithDelegate:(id<PSCExampleRunner>)delegate {
    return [[PSCEmbeddedTestController alloc] initWithNibName:@"EmbeddedNib" bundle:nil];
}

@end

@implementation PSCPDFViewControllerCustomizationChildViewControllerContainmentExample

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - PSCExample

- (id)init {
    if (self = [super init]) {
        self.title = @"Child View Controller containment";
        self.category = PSCExampleCategoryPSPDFViewControllerCustomization;
        self.priority = 30;
    }
    return self;
}

- (UIViewController *)invokeWithDelegate:(id<PSCExampleRunner>)delegate {
    NSURL *samplesURL = [NSBundle.mainBundle.resourceURL URLByAppendingPathComponent:@"Samples"];
    
    NSURL *testURL = [samplesURL URLByAppendingPathComponent:kHackerMagazineExample];
    PSPDFDocument *childDocument = [PSPDFDocument documentWithURL:testURL];
    return [[PSCChildViewController alloc] initWithDocument:childDocument];
}

@end

@implementation PSCPDFViewControllerCustomizationAddingaSimpleUIButtonExample

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - PSCExample

- (id)init {
    if (self = [super init]) {
        self.title = @"Adding a simple UIButton";
        self.category = PSCExampleCategoryPSPDFViewControllerCustomization;
        self.priority = 40;
    }
    return self;
}

- (UIViewController *)invokeWithDelegate:(id<PSCExampleRunner>)delegate {
    NSURL *samplesURL = [NSBundle.mainBundle.resourceURL URLByAppendingPathComponent:@"Samples"];
    NSURL *hackerMagURL = [samplesURL URLByAppendingPathComponent:kHackerMagazineExample];
    
    PSPDFDocument *document = [PSPDFDocument documentWithURL:hackerMagURL];
    return [[PSCButtonPDFViewController alloc] initWithDocument:document];
}

@end

@implementation PSCPDFViewControllerCustomizationAddingMultipleUIButtonsExample

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - PSCExample

- (id)init {
    if (self = [super init]) {
        self.title = @"Adding multiple UIButtons";
        self.category = PSCExampleCategoryPSPDFViewControllerCustomization;
        self.priority = 50;
    }
    return self;
}

- (UIViewController *)invokeWithDelegate:(id<PSCExampleRunner>)delegate {
    NSURL *samplesURL = [NSBundle.mainBundle.resourceURL URLByAppendingPathComponent:@"Samples"];
    NSURL *hackerMagURL = [samplesURL URLByAppendingPathComponent:kHackerMagazineExample];
    
    PSPDFDocument *document = [PSPDFDocument documentWithURL:hackerMagURL];
    return [[PSCImageOverlayPDFViewController alloc] initWithDocument:document];
}

@end

@implementation PSCPDFViewControllerCustomizationCustomToolbarIconExample

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - PSCExample

- (id)init {
    if (self = [super init]) {
        self.title = @"Custom toolbar icon for bookmark item";
        self.category = PSCExampleCategoryPSPDFViewControllerCustomization;
        self.priority = 60;
    }
    return self;
}

- (UIViewController *)invokeWithDelegate:(id<PSCExampleRunner>)delegate {
    NSURL *samplesURL = [NSBundle.mainBundle.resourceURL URLByAppendingPathComponent:@"Samples"];
    NSURL *hackerMagURL = [samplesURL URLByAppendingPathComponent:kHackerMagazineExample];
    
    PSPDFDocument *document = [PSPDFDocument documentWithURL:hackerMagURL];
    PSPDFViewController *pdfController = [[PSPDFViewController alloc] initWithDocument:document];
    pdfController.title = @"Custom toolbar icon for bookmark item";
    [pdfController overrideClass:[PSPDFBookmarkBarButtonItem class] withClass:[PSCCustomBookmarkBarButtonItem class]];
    pdfController.bookmarkButtonItem.tapChangesBookmarkStatus = NO;
    pdfController.rightBarButtonItems = @[pdfController.bookmarkButtonItem, pdfController.viewModeButtonItem];
    return pdfController;
}

@end

@implementation PSCPDFViewControllerCustomizationCompletelyCustomToolbarExample

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - PSCExample

- (id)init {
    if (self = [super init]) {
        self.title = @"Customized Toolbar";
        self.category = PSCExampleCategoryBarButtons;
        self.priority = 70;
    }
    return self;
}

- (UIViewController *)invokeWithDelegate:(id<PSCExampleRunner>)delegate {
    NSURL *samplesURL = [NSBundle.mainBundle.resourceURL URLByAppendingPathComponent:@"Samples"];
    NSURL *hackerMagURL = [samplesURL URLByAppendingPathComponent:kHackerMagazineExample];
    
    PSPDFDocument *document = [PSPDFDocument documentWithURL:hackerMagURL];
    return [[PSCCustomToolbarController alloc] initWithDocument:document];
}

@end

@implementation PSCPDFViewControllerCustomizationTintedToolbarPopoversAlertViewExample

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - PSCExample

- (id)init {
    if (self = [super init]) {
        self.title = @"Tinted Toolbar, Popovers, AlertView";
        self.category = PSCExampleCategoryPSPDFViewControllerCustomization;
        self.priority = 80;
    }
    return self;
}

- (UIViewController *)invokeWithDelegate:(id<PSCExampleRunner>)delegate {
    NSURL *samplesURL = [NSBundle.mainBundle.resourceURL URLByAppendingPathComponent:@"Samples"];
    NSURL *hackerMagURL = [samplesURL URLByAppendingPathComponent:kHackerMagazineExample];
    
    PSPDFDocument *document = [PSPDFDocument documentWithURL:hackerMagURL];
    PSPDFViewController *pdfController = [[PSCTintablePDFViewController alloc] initWithDocument:document];
    return pdfController;
}

@end

@implementation PSCPDFViewControllerCustomizationUIAppearanceExample

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - PSCExample

- (id)init {
    if (self = [super init]) {
        self.title = @"UIAppearance examples";
        self.category = PSCExampleCategoryPSPDFViewControllerCustomization;
        self.priority = 90;
    }
    return self;
}

- (UIViewController *)invokeWithDelegate:(id<PSCExampleRunner>)delegate {
    NSURL *samplesURL = [NSBundle.mainBundle.resourceURL URLByAppendingPathComponent:@"Samples"];
    NSURL *hackerMagURL = [samplesURL URLByAppendingPathComponent:kHackerMagazineExample];
    
    PSPDFDocument *document = [PSPDFDocument documentWithURL:hackerMagURL];
    PSPDFViewController *pdfController = [[PSCAppearancePDFViewController alloc] initWithDocument:document];
    // Present modally to enable new appearance code.
    UINavigationController *navController = [[PSCAppearanceNavigationController alloc] initWithRootViewController:pdfController];
    
    [delegate.currentViewController presentViewController:navController animated:YES completion:NULL];
    return (PSPDFViewController *)nil;
}

@end
