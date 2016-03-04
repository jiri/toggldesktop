//
//  TDBarChart.m
//  TogglDesktop
//
//  Created by Indrek Vändrik on 03/03/16.
//  Copyright © 2016 Alari. All rights reserved.
//

#import "TDBarChart.h"

@implementation TDBarChart

- (void)setNewValue:(int)newValue
{
	self.value = MIN(newValue, 900);
	self.color = [ConvertHexColor hexCodeToNSColor:@"#2CC1E6"];
	[self setNeedsDisplay:YES];
}

- (void)drawRect:(NSRect)dirtyRect
{
	if (self.value)
	{
		long w = self.value * [self bounds].size.width / 900;
		[self.color set];
		[NSBezierPath fillRect:NSMakeRect(0, 0, w, [self bounds].size.height)];
	}
}

@end
