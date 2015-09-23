//
//  LMTextParser.h
//  LMTextView
//
//  Created by Micha Mazaheri on 4/6/13.
//  Copyright (c) 2013 Lucky Marmot. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
	LMTextParserTokenTypeOther			= 0x000,
	LMTextParserTokenTypeBoolean		= 0x001,
	LMTextParserTokenTypeNumber			= 0x002,
	LMTextParserTokenTypeString			= 0x003,
} LMTextParserTokenType;
#define LMTextParserTokenTypeMask		0x000f
#define LMTextParserTokenCustomTypeMask 0xfff0

@protocol LMTextParser <NSObject>

- (void)parse; // Shouldn't be called

@property (strong, nonatomic) NSString*(^stringBlock)(void);

- (void)invalidateString;

- (void)applyAttributesInRange:(NSRange)range withBlock:(void(^)(NSUInteger tokenTypeMask, NSRange range))block;

- (NSArray *)keyPathForObjectAtRange:(NSRange)range objectRange:(NSRange *)correctedRange;

@end
