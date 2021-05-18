#import <Foundation/Foundation.h>

#import "GPBMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface GPBMessage (JSONFormat)

/// Creates a new instance by parsing JSON format. If
/// there is an error the method returns nil and the error is returned in
/// errorPtr (when provided).
///
/// @param json     The JSON object to parse.
/// @param errorPtr An optional error pointer to fill in with a failure reason if
///                 the data can not be parsed.
///
/// @return A new instance of the class messaged.
+ (nullable instancetype)parseFromJSONData:(NSData *)data error:(NSError **)errorPtr;

/// Creates a new instance by parsing JSON format. If
/// there is an error the method returns nil and the error is returned in
/// errorPtr (when provided).
///
/// @param json     The JSON object to parse.
/// @param errorPtr An optional error pointer to fill in with a failure reason if
///                 the data can not be parsed.
///
/// @return A new instance of the class messaged.
+ (nullable instancetype)parseFromJSONObject:(NSDictionary *)json error:(NSError **)errorPtr;

/**
 * Initializes an instance by parsing the data. This method should be sent to
 * the generated message class that the data should be interpreted as. If
 * there is an error the method returns nil and the error is returned in
 * errorPtr (when provided).
 *
 * @note In DEBUG builds, the parsed message is checked to be sure all required
 *       fields were provided, and the parse will fail if some are missing.
 *
 * @note The errors returned are likely coming from the domain and codes listed
 *       at the top of this file and GPBCodedInputStream.h.
 *
 * @param data     The JSON data to parse.
 * @param errorPtr An optional error pointer to fill in with a failure reason if
 *                 the data can not be parsed.
 *
 * @return An initialized instance of the generated class.
 **/
- (nullable instancetype)initWithJSONData:(NSData *)data error:(NSError **)errorPtr;

/**
 * Initializes an instance by parsing the data. This method should be sent to
 * the generated message class that the data should be interpreted as. If
 * there is an error the method returns nil and the error is returned in
 * errorPtr (when provided).
 *
 * @note In DEBUG builds, the parsed message is checked to be sure all required
 *       fields were provided, and the parse will fail if some are missing.
 *
 * @note The errors returned are likely coming from the domain and codes listed
 *       at the top of this file and GPBCodedInputStream.h.
 *
 * @param data     The JSON object to parse.
 * @param errorPtr An optional error pointer to fill in with a failure reason if
 *                 the data can not be parsed.
 *
 * @return An initialized instance of the generated class.
 **/
- (nullable instancetype)initWithJSONObject:(NSDictionary *)json error:(NSError **)errorPtr;

/**
 * Parses the given JSON data as this message's class, and merges those values into
 * this message.
 *
 * @param data              The JSON representation of the message to merge.
 *
 * @exception GPBCodedInputStreamException Exception thrown when parsing was
 *                                         unsuccessful.
 **/
- (void)mergeFromJSONData:(NSData *)data;

/**
 * Parses the given JSON object as this message's class, and merges those values into
 * this message.
 *
 * @param data              The JSON representation of the message to merge.
 *
 * @exception GPBCodedInputStreamException Exception thrown when parsing was
 *                                         unsuccessful.
 **/
- (void)mergeFromJSONObject:(NSDictionary *)json;

/**
 * Serializes the message to an JSON NSData.
 *
 * If there is an error while generating the data, nil is returned.
 *
 * @note This value is not cached, so if you are using it repeatedly, cache
 *       it yourself.
 *
 * @note In DEBUG ONLY, the message is also checked for all required field,
 *       if one is missing, nil will be returned.
 *
 * @return The JSON representation of the message.
 **/
- (nullable NSData *)JSONData;

/**
 * Serializes the message to an JSON object.
 *
 * If there is an error while generating the data, nil is returned.
 *
 * @note This value is not cached, so if you are using it repeatedly, cache
 *       it yourself.
 *
 * @note In DEBUG ONLY, the message is also checked for all required field,
 *       if one is missing, nil will be returned.
 *
 * @return The JSON representation of the message.
 **/
- (nullable NSDictionary *)JSONObject;

@end

NS_ASSUME_NONNULL_END
