// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#import <Foundation/Foundation.h>

#import "MSACDistribute.h"

@class MSACReleaseDetails;

/**
 * Return the application's main bundle.
 *
 * @return Instance of NSBundle, the Application's main bundle.
 */
NSBundle *MSACDistributeBundle(void);

/**
 * Return a localized string for the given token.
 *
 * @param stringToken The string token that will be looked for in the .strings file.
 *
 * @return A localized string.
 *
 * @discussion This needs the AppCenterDistributeResources.bundle to be added to the project. If the bundle is missing, the method will
 * return the provided stringToken. In case nil or an empty string is passed to the method, it will return an empty string. If the .strings
 * file does not contain a string for the token, it will return the token.
 */
NSString *MSACDistributeLocalizedString(NSString *stringToken);

/**
 * Check compliance of given version against semantic versioning format.
 *
 * @param version A version to check against semantic versioning format.
 *
 * @return `YES` if the given version is compatible with semantic versioning format.
 */
BOOL MSACisSemVerFormat(NSString *version);

/**
 * Compare current release for this hosting app with given release.
 *
 * @param release Release to compare with current app release.
 *
 * @return The comparison result determining releases precedence.
 */
NSComparisonResult MSACCompareCurrentReleaseWithRelease(MSACReleaseDetails *release);

/**
 * Get package hash of the application.
 *
 * @return A package hash string.
 */
NSString *MSACPackageHash(void);

@interface MSACDistributeUtil : NSObject

/**
 * Check if the given update track is valid or not.
 *
 * @return YES if it is valid, NO otherwise.
 */
+ (BOOL)isValidUpdateTrack:(MSACUpdateTrack)updateTrack;

/**
 * Finds and returns an active window to be used as a presentation anchor.
 *
 * @return Presentation anchor.
 */
+ (ASPresentationAnchor)getPresentationAnchor API_AVAILABLE(ios(13));

@end
