//
//  IJTSYN-Scan.h
//  IJTSYN Scan
//
//  Created by 聲華 陳 on 2015/9/12.
//
//

#import <Foundation/Foundation.h>

@interface IJTSYN_Scan : NSObject

typedef NS_ENUM(u_int8_t, IJTSYN_ScanFlags) {
    IJTSYN_ScanFlagsClose = 0x00,
    IJTSYN_ScanFlagsOpen = 0x01,
    IJTSYN_ScanFlagsFiltered = 0x02
};

/**
 * syn scan callback function define
 * id self
 * SEL method
 * u_int16_t port
 * NSString *name
 * IJTUDP_ScanFlags flags
 * id object
 */
typedef void (*SYNScanCallback)(id, SEL, u_int16_t, NSString *, IJTSYN_ScanFlags, id);

#define SYNSCAN_CALLBACK_SEL @selector(synScanPort:portName:flags:object:)

#define SYNSCAN_CALLBACK_METHOD \
- (void)synScanPort: (u_int16_t)port \
portName: (NSString *)portName \
flags: (IJTSYN_ScanFlags)flags \
object: (id)object

@property (nonatomic) BOOL errorHappened;
@property (nonatomic) int errorCode;

- (id)init;
- (void)dealloc;
- (void)open;
- (void)close;

/**
 * 設定目標
 * @param setTarget 目標, ip or hostname
 * @return 發生h_error錯誤傳回-2, 成功傳回0
 */
- (int)setTarget: (NSString *)target;

/**
 * 設定port
 */
- (void)setStartPort: (u_int16_t)startPort endPort: (u_int16_t)endPort;

/**
 * 開始送出封包
 * @param injectWithInterval inject interval (microsecond)
 * @param randomization port 隨機
 * @param stop 停止
 * @param timeout udp read timeout
 * @return 成功傳回0, 失敗傳回-1, host down傳回-2
 */
- (int)injectWithInterval: (useconds_t)interval
            randomization: (BOOL)randomization
                     stop: (BOOL *)stop
                  timeout: (u_int32_t)timeout
                   target: (id)target
                 selector: (SEL)selector
                   object: (id)object;

/**
 * 取得要送出的封包數
 * @return 傳回數量
 */
- (u_int64_t)getTotalInjectCount;

/**
 * 取得還有多少封包要送出
 * @return 傳回數量
 */
- (u_int64_t)getRemainInjectCount;


@end
