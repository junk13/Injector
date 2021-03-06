//
//  IJTPingTaskTableViewCell.h
//  Injector
//
//  Created by 聲華 陳 on 2015/8/21.
//  Copyright (c) 2015年 Qbsuran Alang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IJTPingTaskTableViewCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UILabel *amountLabel;
@property (weak, nonatomic) IBOutlet UILabel *targetLabel;
@property (weak, nonatomic) IBOutlet UILabel *sourceLabel;
@property (weak, nonatomic) IBOutlet UILabel *fragmentLabel;
@property (weak, nonatomic) IBOutlet UILabel *tosLabel;
@property (weak, nonatomic) IBOutlet UILabel *ttlLabel;
@property (weak, nonatomic) IBOutlet UILabel *payloadSizeLabel;

@property (strong, nonatomic) IBOutletCollection(UILabel) NSArray *labels;

@end
