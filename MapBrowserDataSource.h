//
//  MapBrowserDataSource.h
//  TrenchBroom
//
//  Created by Kristian Duske on 03.08.11.
//  Copyright 2011 TU Berlin. All rights reserved.
//

@class MapWindowController;

@interface MapBrowserDataSource : NSObject <NSOutlineViewDataSource> {
    MapWindowController* mapWindowController;
}

- (void)setMapWindowController:(MapWindowController *)theMapWindowController;

@end