/*
 原作信息：
 Melody//旋律
 Plays a melody//奏响一段旋律
 circuit://电路
 * 8-ohm speaker on digital pin 8//8欧姆发声元器件连接数字引脚8
 created 21 Jan 2010//2010年1月21日创作
 modified 30 Aug 2011//2011年8月30日修改
 by Tom Igoe//（作者）
 This example code is in the public domain.//这是一个公开的代码范例
 http://www.arduino.cc/en/Tutorial/Tone 
*/
//作品内容有改动，加入了一段小星星，以及bilibili镇站神曲only my railgun




//宏定义  琴键音调 对应音乐代码 
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
 
#define NOTE_C1  262
#define NOTE_C2  294
#define NOTE_C3  330
#define NOTE_C4  350
#define NOTE_C5  393
#define NOTE_C6  441
#define NOTE_C7  495

#define NOTE_CH1  525
#define NOTE_CH2  589
#define NOTE_CH3  661
#define NOTE_CH4  700
#define NOTE_CH5  786
#define NOTE_CH6  882
#define NOTE_CH7  990
/*
补充内容：
基本音级的名称有音名和唱名两种标记方法：
现代音乐用七个英文字母CDEFGAB来标记音名，唱名则利用读音来表示。
C大调基本音级的音名与其对应的唱名则是do、re、mi、fa、 sol、la、si 七个读音。
按顺序升调，每升一阶以上一阶的si作为下一阶的do。
如：A3与B3唱名相同，为mi；但音名不同，即音高不同，相差一个“八度”。
*/



// notes in the melody:
// 定义一个数组，即旋律的内容，NOTE_xx表示音调，0表示空拍
int melody1[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
// 琴键音律持续时长：4代表四分音符，8代表八分音符，以此类推
// 定义一个数组，即旋律的节奏
int noteDurations1[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

// 一段自定义小星星
int melody2[] = {
  NOTE_C1, NOTE_C1, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, NOTE_C5, 0,
  NOTE_C4, NOTE_C4,NOTE_C3, NOTE_C3, NOTE_C2, NOTE_C2, NOTE_C1, 0, 
  NOTE_C5, NOTE_C5, NOTE_C4, NOTE_C4, NOTE_C3, NOTE_C3, NOTE_C2, 0,
  NOTE_C5, NOTE_C5, NOTE_C4, NOTE_C4, NOTE_C3, NOTE_C3, NOTE_C2, 0,
  NOTE_C1, NOTE_C1, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, NOTE_C5, 0,
  NOTE_C4, NOTE_C4,NOTE_C3, NOTE_C3, NOTE_C2, NOTE_C2, NOTE_C1, 0
};
int noteDurations2[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
};

// 另一段自定义only my railgun
int melody3[] = {
  NOTE_CH1, NOTE_C7, NOTE_C5, 0, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C6, 0, NOTE_C6, NOTE_C7,NOTE_CH1, NOTE_CH2, NOTE_C7,  NOTE_C5, NOTE_CH4, NOTE_CH2,
  NOTE_CH2, NOTE_CH2, NOTE_CH3, 0, 
  
  NOTE_CH1, NOTE_C7, NOTE_C5, 0, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C6, 0, NOTE_C6, NOTE_C7,NOTE_CH1, NOTE_CH2, NOTE_C6,0,
  NOTE_C6, NOTE_C7, NOTE_CH1, NOTE_CH2, NOTE_C7, NOTE_C5, NOTE_C3, NOTE_C5, 0, 
  
  NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_CH1, NOTE_C7, NOTE_C5, NOTE_C3, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  
  NOTE_CH1, NOTE_CH1, NOTE_C7, NOTE_CH1, NOTE_CH2, NOTE_CH1, 0,
  NOTE_CH1, NOTE_C7, NOTE_CH1, NOTE_CH2, NOTE_CH3, 0,
  NOTE_CH3, NOTE_CH4, NOTE_CH3, NOTE_CH2, 0, NOTE_CH3, NOTE_CH2, NOTE_CH1, NOTE_CH5, NOTE_CH3, 0,
  
  NOTE_CH1, NOTE_CH1, NOTE_C7, NOTE_CH1, NOTE_CH2, NOTE_CH1, 0,
  NOTE_CH1, NOTE_C7, NOTE_CH1, NOTE_CH2, NOTE_CH3, NOTE_C6, 0,
  NOTE_CH2, NOTE_CH1, NOTE_C7, NOTE_CH1, 0, NOTE_C7, NOTE_C6, NOTE_C6, 0,
  
  NOTE_CH3, NOTE_CH3, NOTE_CH3, NOTE_CH3, NOTE_CH3, 0, NOTE_CH3, NOTE_CH2, NOTE_CH1, 0,
  NOTE_C7, NOTE_C7, NOTE_CH5,  NOTE_CH5, 0,
  NOTE_CH5,  NOTE_CH5, NOTE_CH5, NOTE_CH4,  NOTE_CH3, NOTE_CH2,  NOTE_CH3, NOTE_CH2, NOTE_CH1, NOTE_C7, 0,
  NOTE_C7, NOTE_C7, NOTE_C6, NOTE_CH1, 0,
  
  NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, 0, NOTE_C6, NOTE_C7, NOTE_CH1, 0,
  NOTE_C7, NOTE_C7, NOTE_CH5, NOTE_CH5, 0,
  NOTE_C5, NOTE_C4, 0, NOTE_C4, NOTE_C3, 0,NOTE_C4, NOTE_C5, NOTE_C6, 0,
  NOTE_CH1, NOTE_CH1, NOTE_C7, NOTE_C6, NOTE_C7, 0,
  
  NOTE_CH1, NOTE_C7, NOTE_C5, 0, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C6, 0, NOTE_C6, NOTE_C7,NOTE_CH1, NOTE_CH2, NOTE_C7,  NOTE_C5, NOTE_CH4, NOTE_CH2,
  NOTE_CH2, NOTE_CH2, NOTE_CH3, 0, 
  
  NOTE_CH1, NOTE_C7, NOTE_C5, 0, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C6, 0, NOTE_C6, NOTE_C7,NOTE_CH1, NOTE_CH2, NOTE_C6,0,
  NOTE_C6, NOTE_C7, NOTE_CH1, NOTE_CH2, NOTE_C7, NOTE_C5, NOTE_C3, NOTE_C5, 0, 
  
  NOTE_CH1, NOTE_C7, NOTE_C5, 0, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C6, 0, NOTE_C6, NOTE_C7,NOTE_CH1, NOTE_CH2, NOTE_C7,  NOTE_C5, NOTE_CH4, NOTE_CH2,
  NOTE_CH2, NOTE_CH2, NOTE_CH3, 0, 
  
  NOTE_CH1, NOTE_C7, NOTE_C5, 0, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_C6, 0, NOTE_C6, NOTE_C7,NOTE_CH1, NOTE_CH2, NOTE_C6,0,
  NOTE_C6, NOTE_C7, NOTE_CH1, NOTE_CH2, NOTE_C7, NOTE_C5, NOTE_C3, NOTE_C5, 0, 
  
  NOTE_C5, NOTE_C6, NOTE_C6, 0,
  NOTE_CH1, NOTE_C7, NOTE_C5, NOTE_C3, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, 0,
  
};
int noteDurations3[] = {
  4, 4, 4, 8, 4, 4, 4, 8, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 8, 4, 4, 4, 8, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 8, 4, 4, 4, 8, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 8, 4, 4, 4, 8, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 8, 4, 4, 4, 8, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};

void setup() {
  // iterate over the notes of the melody:
  // 琴键旋律的迭代（定义一个变量thisNote来限制旋律的长短，并与前面的数组对应上）
  for (int thisNote1 = 0; thisNote1 < 8; thisNote1++) {

    
    
    // to calculate the note duration, take one second divided by the note type.
    // 用来计算琴键持续时长，把1s按照音符类型来划分 
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    //例如：四分音符是1000ms的四分之一，即四分之一秒，其他同理
    
    //下面是对于音符类型的设定：
    int noteDuration1 = 1000 / noteDurations1[thisNote1];
    tone(8, melody1[thisNote1], noteDuration1);//tone（引脚，频率-音调，持续时长）

    
    
    // to distinguish the notes, set a minimum time between them.
    // 为了区分这些琴键，设置一个最小间隔
    // the note's duration + 30% seems to work well:
    // 这个琴键间隔+30%似乎比较好：
    
    //下面是对琴键间隔的设定：
    int pauseBetweenNotes1 = noteDuration1 * 1.30;//定义琴键间隔时长
    delay(pauseBetweenNotes1);//设置延时
  }
  delay(1000);
  
  // 这里是我自定义的一段小星星
  for (int thisNote2 = 0; thisNote2 < 48; thisNote2++) {
    int noteDuration2 = 1000 / noteDurations2[thisNote2];
    tone(8, melody2[thisNote2], noteDuration2);

    int pauseBetweenNotes2 = noteDuration2 * 1.30;
    delay(pauseBetweenNotes2);
  }  
  delay(1000);
  // 这里是我自定义的一段ONLY MY RAILGUN
  for (int thisNote3 = 0; thisNote3 < 170; thisNote3++) {
    int noteDuration3 = 1000 / noteDurations3[thisNote3];
    tone(8, melody3[thisNote3], noteDuration3);

    int pauseBetweenNotes3 = noteDuration3 * 1.30;
    delay(pauseBetweenNotes3);
  }    
       
}

void loop() {
  // 这里是我自定义的一段ONLY MY RAILGUN
  for (int thisNote3 = 0; thisNote3 < 170; thisNote3++) {
    int noteDuration3 = 1000 / noteDurations3[thisNote3];
    tone(8, melody3[thisNote3], noteDuration3);

    int pauseBetweenNotes3 = noteDuration3 * 1.30;
    delay(pauseBetweenNotes3);
  }    
}