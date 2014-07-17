//
//  IDDCore.h
//  IddictionSDK
//
//  Created by Jernej Strasner on 11/16/12.
//  Copyright (c) 2012 Iddiction, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IddictionSDK : NSObject

/// ---------------------------------------------------------------------
/// @name Initialization
/// ---------------------------------------------------------------------

/// Initializes the SDK using the assigned app credentials and allows all subsequent SDK calls to be executed.
/// This method should be called on every launch from applicationDidFinishLaunching:withOptions: in your app delegate.
///
/// @note The class IDDCore has been deprecated, please use IddictionSDK as an entry point.
///
/// @param appHandle			The app handle assigned to the app on Xplode.
/// @param appSecret			The app secret assigned to the app on Xplode.
/// @param completionHandler	A block that gets called when the SDK is initialized.

+ (void)initializeWithAppHandle:(NSString *)appHandle
					  appSecret:(NSString *)appSecret
				   onCompletion:(void(^)(NSError *error))completionHandler;

/// ---------------------------------------------------------------------
/// @name Properties
/// ---------------------------------------------------------------------

/// Returns the app handle that was set using initializeWithAppHandle:appSecret:onCompletion:.
///
/// @return The app handle.

+ (NSString *)appHandle;

/// Returns the appSecret that was set using initializeWithAppHandle:appSecret:onCompletion:.
///
/// @return The app secret.

+ (NSString *)appSecret;

/// Returns *YES* if initializeWithAppHandle:appSecret:onCompletion: has been called and successfully registered with the server.
/// If this method returns *NO*, no other operations with the SDK will work.
///
/// @return *YES* if the SDK was successfully initialized, *NO* otherwise.

+ (BOOL)isInitialized;

/// The error that was generated during the SDK initialization proccess.
///
/// @return An error object or nil if there was no error on initalization.

+ (NSError *)initializationError;

@end

@compatibility_alias IDDCore IddictionSDK;