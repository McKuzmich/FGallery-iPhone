//
//  FGalleryPhoto.h
//  TNF_Trails
//
//  Created by Grant Davis on 5/20/10.
//  Copyright 2010 Factory Design Labs. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol FGalleryPhotoDelegate;

@interface FGalleryPhoto : NSObject {
	
	// value which determines if the photo was initialized with local file paths or network paths.
	BOOL _useNetwork;
	
	BOOL _isThumbLoading;
	BOOL _hasThumbLoaded;
	
	BOOL _isFullsizeLoading;
	BOOL _hasFullsizeLoaded;
    
    BOOL _loadsFromDocuments;
	
	NSMutableData *_thumbData;
	NSMutableData *_fullsizeData;
	
	NSURLConnection *_thumbConnection;
	NSURLConnection *_fullsizeConnection;
	
	NSString *_thumbUrl;
	NSString *_fullsizeUrl;
	
	UIImage *_thumbnail;
	UIImage *_fullsize;
	
	NSObject <FGalleryPhotoDelegate> *_delegate;
	
	NSUInteger tag;
}


- (id)initWithThumbnailUrl:(NSString*)thumb fullsizeUrl:(NSString*)fullsize delegate:(NSObject<FGalleryPhotoDelegate>*)delegate;
- (id)initWithThumbnailPath:(NSString*)thumb fullsizePath:(NSString*)fullsize delegate:(NSObject<FGalleryPhotoDelegate>*)delegate;
- (id)initFromDocumentsWithThumbnailPath:(NSString*)thumb fullsizePath:(NSString*)fullsize delegate:(NSObject<FGalleryPhotoDelegate>*)delegate;

- (void)loadThumbnail;
- (void)loadFullsize;

- (void)unloadFullsize;
- (void)unloadThumbnail;

@property NSUInteger tag;

@property (readonly) BOOL isThumbLoading;
@property (readonly) BOOL hasThumbLoaded;

@property (readonly) BOOL isFullsizeLoading;
@property (readonly) BOOL hasFullsizeLoaded;

@property (readwrite) BOOL loadsFromDocuments;

@property (nonatomic,retain) UIImage *thumbnail;
@property (nonatomic,retain) UIImage *fullsize;

@property (nonatomic,assign) NSObject<FGalleryPhotoDelegate> *delegate;

@end


@protocol FGalleryPhotoDelegate

@required
- (void)galleryPhoto:(FGalleryPhoto *)photo didLoadThumbnail:(UIImage*)image;
- (void)galleryPhoto:(FGalleryPhoto *)photo didLoadFullsize:(UIImage*)image;

@optional
- (void)galleryPhoto:(FGalleryPhoto *)photo willLoadThumbnailFromUrl:(NSString*)url;
- (void)galleryPhoto:(FGalleryPhoto *)photo willLoadFullsizeFromUrl:(NSString*)url;

- (void)galleryPhoto:(FGalleryPhoto *)photo willLoadThumbnailFromPath:(NSString*)path;
- (void)galleryPhoto:(FGalleryPhoto *)photo willLoadFullsizeFromPath:(NSString*)path;
- (void)galleryPhoto:(FGalleryPhoto *)photo willLoadFullsizeOptimizedFromPath:(NSString *)path;

@end
