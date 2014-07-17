//
//  IddictionSDK+Promotions.h
//  IddictionSDK
//
//  Created by Jernej Strasner on 10/16/12.
//  Copyright (c) 2012 Iddiction, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, IDDPromotionsHandlePosition) {
	IDDPromotionsHandlePositionBottom = 0,
	IDDPromotionsHandlePositionTop
};

/** Notifications */

// The key in the user info dictionary which contains the breakpoint
static NSString * const IDDPromotionNotificationBreakpointKey				= @"com.iddiction.promotions.notification.key.breakpoint";

static NSString * const IDDPromotionWillOpenNotification					= @"com.iddiction.promotions.notification.willOpen";
static NSString * const IDDPromotionDidOpenNotification						= @"com.iddiction.promotions.notification.didOpen";
static NSString * const IDDPromotionWillCloseNotification					= @"com.iddiction.promotions.notification.willClose";
static NSString * const IDDPromotionDidCloseNotification					= @"com.iddiction.promotions.notification.didClose";
static NSString * const IDDPromotionWillLoadNotification					= @"com.iddiction.promotions.notification.willLoad";
static NSString * const IDDPromotionDidLoadNotification						= @"com.iddiction.promotions.notification.didLoad";
static NSString * const IDDPromotionDidFailLoadingNotification				= @"com.iddiction.promotions.notification.didFailLoading";

static NSString * const IDDPromotionGridWillOpenNotification				= @"com.iddiction.promotions.grid.notification.willOpen";
static NSString * const IDDPromotionGridDidOpenNotification					= @"com.iddiction.promotions.grid.notification.didOpen";
static NSString * const IDDPromotionGridWillCloseNotification				= @"com.iddiction.promotions.grid.notification.willClose";
static NSString * const IDDPromotionGridDidCloseNotification				= @"com.iddiction.promotions.grid.notification.didClose";
static NSString * const IDDPromotionGridWillShowHandleNotification			= @"com.iddiction.promotions.grid.notification.willShowHandle";
static NSString * const IDDPromotionGridDidShowHandleNotification			= @"com.iddiction.promotions.grid.notification.didShowHandle";
static NSString * const IDDPromotionGridWillHideHandleNotification			= @"com.iddiction.promotions.grid.notification.willHideHandle";
static NSString * const IDDPromotionGridDidHideHandleNotification			= @"com.iddiction.promotions.grid.notification.didHideHandle";
static NSString * const IDDPromotionGridWillLoadNotification				= @"com.iddiction.promotions.grid.notification.willLoad";
static NSString * const IDDPromotionGridDidLoadNotification					= @"com.iddiction.promotions.grid.notification.didLoad";
static NSString * const IDDPromotionGridDidFailLoadingNotification			= @"com.iddiction.promotions.grid.notification.didFailLoading";

/// An object can conform to the IDDPromotionsDelegate protocol in order to respond when promotions are loaded and presented.
@protocol IDDPromotionsDelegate <NSObject>

@optional

/** @name Promotions */

/// A promotion is about to open.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.

- (void)promotionWillOpenForBreakpoint:(NSString *)breakpoint;

/// A promotion's opening animation has finished.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.

- (void)promotionDidOpenForBreakpoint:(NSString *)breakpoint;

/// A promotion is about to close.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.

- (void)promotionWillCloseForBreakpoint:(NSString *)breakpoint;

/// A promotion's closing animation has finished.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.

- (void)promotionDidCloseForBreakpoint:(NSString *)breakpoint;

/// A promotion will start loading.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.

- (void)promotionWillLoadForBreakpoint:(NSString *)breakpoint;

/// A promotion finished loading.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.

- (void)promotionDidLoadForBreakpoint:(NSString *)breakpoint;

/// A promotion failed to load.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.

- (void)promotionDidFailLoadingForBreakpoint:(NSString *)breakpoint;

/** @name Grid */

/// The grid is about to open.

- (void)gridWillOpen;

/// The grid's opening animation finished.

- (void)gridDidOpen;

/// The grid is about to close.

- (void)gridWillClose;

/// The grid's closing animation finished.

- (void)gridDidClose;

/// The grid will start loading.

- (void)gridWillLoad;

/// The grid finished loading.

- (void)gridDidLoad;

/// The grid failed to load.

- (void)gridDidFailLoading;

/// The grid is about to show the handle.

- (void)gridWillShowHandle;

/// The grid handle opening animation finished.

- (void)gridDidShowHandle;

/// The grid is about to hide the handle.

- (void)gridWillHideHandle;

/// The grid handle closing animation finished.

- (void)gridDidHideHandle;

@end

/**
 Use IDDPromotions to load and present promotions.
 */

@interface IDDPromotions : NSObject

/// Returns the promotions delegate.
///
/// Promotion delegates have to conform to the formal protocol IDDPromotionsDelegate.
/// @return The promotion delegate.

+ (id<IDDPromotionsDelegate>)delegate;

/// Sets the promotions delegate.
///
/// Promotion delegates have to conform to the formal protocol IDDPromotionsDelegate.

+ (void)setDelegate:(id<IDDPromotionsDelegate>)delegate;

/// Checks whether promotions are supported on the current device.
///
/// @return *YES* if the device is supported, *NO* otherwise.

+ (BOOL)isCurrentDeviceSupported;

/// Preloads the default promotion for presenting it later.
///
/// Nothing is presented on-screen, the data is only loaded from the server and cached.

+ (void)cachePromotion;

/// Preloads the promotion for a specific breakpoint for presenting it later.
///
/// Nothing is presented on-screen, the data is only loaded from the server and cached.
///
///	@param breakpoint Name of the breakpoint.

+ (void)cachePromotionForBreakpoint:(NSString *)breakpoint;

/// Presents a full-screen view controller with the default promotion.
///
/// @param completionHandler	The completion handler.	It is executed when the promotion is closed.

+ (void)presentPromotionOnCompletion:(void(^)(void))completionHandler;

/// Presents a full-screen view controller with the promotion for the specified breakpoint.
///
///
///	@param breakpoint Name of the breakpoint.
/// @param completionHandler	The completion handler.	It is executed when the promotion is closed.

+ (void)presentPromotionForBreakpoint:(NSString *)breakpoint
						 onCompletion:(void(^)(void))completionHandler;

/// Checks if the default promotion is ready to be presented.
///
/// @return *YES* if the default promotion is ready to be presented, *NO* otherwise.

+ (BOOL)isPromotionReady;

/// Checks if the promotion for the specified breakpoint is ready to be presented.
///
///
///	@param breakpoint Name of the breakpoint.
///
/// @return *YES* if a promotion is ready for the specified breakpoint, *NO* otherwise.

+ (BOOL)isPromotionReadyForBreakpoint:(NSString *)breakpoint;

/// Returns the state of the promotion.
///
/// The state changes when the presentPromotion and dismissPromotion methods are called.
/// @return *YES* if open, *NO* if closed.

+ (BOOL)isPromotionOpen;

/// Adds a grid handle to the screen and optionally opens the grid in full-screen.
///
/// @param handlePosition		The position of the handle on the screen. IDDPromotionsHandlePositionBottom or IDDPromotionsHandlePositionTop.
/// @param openGrid				*YES* to present the grid full-screen, *NO* only to add the handle.
/// @param completionHandler	The completion handler.	It is executed when the grid is closed.

+ (void)setupGridHandleAtPosition:(IDDPromotionsHandlePosition)handlePosition
						 openGrid:(BOOL)openGrid
					 onCompletion:(void(^)(void))completionHandler;

/// Hides the presented grid but keeps the handle visible.

+ (void)dismissGrid;

/// Hides the grid along with its handle and removes it from memory.
/// The grid can be shown again by using setupGridHandleAtPosition:openGrid:onCompletion:.

+ (void)destroyGrid;

/// Shows the pull handle of an already loaded grid in closed state and controls the bouncing animation.
/// The pull handle can be shown only after the grid has been loaded using
/// setupGridHandleAtPosition:openGrid:completionHandler: and hidden using hideGridHandle.
///
/// @param bounce		*YES* for bouncing animation, *NO* for sliding animation.

+ (void)showGridHandleAndBounce:(BOOL)bounce;

/// Hides the handle of an already loaded grid.
/// The pull handle can be hidden only after the grid has been loaded using
/// setupGridHandleAtPosition:openGrid:completionHandler:.

+ (void)hideGridHandle;

/// Checks if the grid is ready to be presented.
///
/// @return *YES* if the grid is ready to be presented, *NO* otherwise.

+ (BOOL)isGridReady;

/// Returns the state of the grid.
///
/// The state changes when the present and dismiss methods are called.
/// @return *YES* if open, *NO* if closed.

+ (BOOL)isGridOpen;

/// Returns the visibility of the grid. The grid is visible if the handle is visible or if it is presented full-screen.
///
/// The state changes when the showGridHandleAndBounce: and hideGridHandle methods are called.
/// @return *YES* if visible, *NO* if hidden.

+ (BOOL)isGridVisible;

/// Sets the allowed interface orientations for promotions.
///
/// If you want to disable certain orientations for different view controllers, call this method before presenting any promotions.
///
/// @note This method is optional.
///	@param allowedOrientations Allowed promotion orientations. For possible values, see Apple's UIApplication documentation about UIInterfaceOrientationMask.

+ (void)setAllowedPromotionOrientations:(UIInterfaceOrientationMask)allowedOrientations;

@end
