//
//  SPUDownloader.h
//  Downloader
//
//  Created by Mayur Pawashe on 4/1/16.
//  Copyright © 2016 Sparkle Project. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SPUDownloaderProtocol.h"

@protocol SPUDownloaderDelegate;

// This object implements the protocol which we have defined. It provides the actual behavior for the service. It is 'exported' by the service to make it available to the process hosting the service over an NSXPCConnection.
SPU_OBJC_DIRECT_MEMBERS @interface SPUDownloader : NSObject <SPUDownloaderProtocol>

// Due to XPC remote object reasons, this delegate is strongly referenced
// Invoke cleanup when done with this instance
- (instancetype)initWithDelegate:(id <SPUDownloaderDelegate>)delegate;

// The session configuration used for all in-process downloads. Set this to
// customize the underlying NSURLSession. Defaults to nil, in which case
// +[NSURLSessionConfiguration defaultSessionConfiguration] is used.
// Has no effect when the XPC downloader service is active.
@property (class, nullable, copy) NSURLSessionConfiguration *sharedSessionConfiguration;

// A client credential to present when the server issues a client certificate
// challenge (i.e. mutual TLS). When set, SPUDownloader handles the challenge
// directly — this is more reliable than pre-loading the credential into
// URLCredentialStorage. Has no effect when the XPC downloader service is active.
@property (class, nullable, strong) NSURLCredential *sharedClientCredential;

@end
