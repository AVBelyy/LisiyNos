#!/usr/bin/env python

res = [[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31], [1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351, 378, 406, 435, 465, 496], [1, 4, 10, 20, 35, 56, 84, 120, 165, 220, 286, 364, 455, 560, 680, 816, 969, 1140, 1330, 1540, 1771, 2024, 2300, 2600, 2925, 3276, 3654, 4060, 4495, 4960, 5456], [1, 5, 15, 35, 70, 126, 210, 330, 495, 715, 1001, 1365, 1820, 2380, 3060, 3876, 4845, 5985, 7315, 8855, 10626, 12650, 14950, 17550, 20475, 23751, 27405, 31465, 35960, 40920, 46376], [1, 6, 21, 56, 126, 252, 462, 792, 1287, 2002, 3003, 4368, 6188, 8568, 11628, 15504, 20349, 26334, 33649, 42504, 53130, 65780, 80730, 98280, 118755, 142506, 169911, 201376, 237336, 278256, 324632], [1, 7, 28, 84, 210, 462, 924, 1716, 3003, 5005, 8008, 12376, 18564, 27132, 38760, 54264, 74613, 100947, 134596, 177100, 230230, 296010, 376740, 475020, 593775, 736281, 906192, 1107568, 1344904, 1623160, 1947792], [1, 8, 36, 120, 330, 792, 1716, 3432, 6435, 11440, 19448, 31824, 50388, 77520, 116280, 170544, 245157, 346104, 480700, 657800, 888030, 1184040, 1560780, 2035800, 2629575, 3365856, 4272048, 5379616, 6724520, 8347680, 10295472], [1, 9, 45, 165, 495, 1287, 3003, 6435, 12870, 24310, 43758, 75582, 125970, 203490, 319770, 490314, 735471, 1081575, 1562275, 2220075, 3108105, 4292145, 5852925, 7888725, 10518300, 13884156, 18156204, 23535820, 30260340, 38608020, 48903492], [1, 10, 55, 220, 715, 2002, 5005, 11440, 24310, 48620, 92378, 167960, 293930, 497420, 817190, 1307504, 2042975, 3124550, 4686825, 6906900, 10015005, 14307150, 20160075, 28048800, 38567100, 52451256, 70607460, 94143280, 124403620, 163011640, 211915132], [1, 11, 66, 286, 1001, 3003, 8008, 19448, 43758, 92378, 184756, 352716, 646646, 1144066, 1961256, 3268760, 5311735, 8436285, 13123110, 20030010, 30045015, 44352165, 64512240, 92561040, 131128140, 183579396, 254186856, 348330136, 472733756, 635745396, 847660528], [1, 12, 78, 364, 1365, 4368, 12376, 31824, 75582, 167960, 352716, 705432, 1352078, 2496144, 4457400, 7726160, 13037895, 21474180, 34597290, 54627300, 84672315, 129024480, 193536720, 286097760, 417225900, 600805296, 854992152, 1203322288, 1676056044, 2311801440L, 3159461968L], [1, 13, 91, 455, 1820, 6188, 18564, 50388, 125970, 293930, 646646, 1352078, 2704156, 5200300, 9657700, 17383860, 30421755, 51895935, 86493225, 141120525, 225792840, 354817320, 548354040, 834451800, 1251677700, 1852482996, 2707475148L, 3910797436L, 5586853480L, 7898654920L, 11058116888L], [1, 14, 105, 560, 2380, 8568, 27132, 77520, 203490, 497420, 1144066, 2496144, 5200300, 10400600, 20058300, 37442160, 67863915, 119759850, 206253075, 347373600, 573166440, 927983760, 1476337800, 2310789600L, 3562467300L, 5414950296L, 8122425444L, 12033222880L, 17620076360L, 25518731280L, 36576848168L], [1, 15, 120, 680, 3060, 11628, 38760, 116280, 319770, 817190, 1961256, 4457400, 9657700, 20058300, 40116600, 77558760, 145422675, 265182525, 471435600, 818809200, 1391975640, 2319959400L, 3796297200L, 6107086800L, 9669554100L, 15084504396L, 23206929840L, 35240152720L, 52860229080L, 78378960360L, 114955808528L], [1, 16, 136, 816, 3876, 15504, 54264, 170544, 490314, 1307504, 3268760, 7726160, 17383860, 37442160, 77558760, 155117520, 300540195, 565722720, 1037158320, 1855967520, 3247943160L, 5567902560L, 9364199760L, 15471286560L, 25140840660L, 40225345056L, 63432274896L, 98672427616L, 151532656696L, 229911617056L, 344867425584L], [1, 17, 153, 969, 4845, 20349, 74613, 245157, 735471, 2042975, 5311735, 13037895, 30421755, 67863915, 145422675, 300540195, 601080390, 1166803110, 2203961430L, 4059928950L, 7307872110L, 12875774670L, 22239974430L, 37711260990L, 62852101650L, 103077446706L, 166509721602L, 265182149218L, 416714805914L, 646626422970L, 991493848554L], [1, 18, 171, 1140, 5985, 26334, 100947, 346104, 1081575, 3124550, 8436285, 21474180, 51895935, 119759850, 265182525, 565722720, 1166803110, 2333606220L, 4537567650L, 8597496600L, 15905368710L, 28781143380L, 51021117810L, 88732378800L, 151584480450L, 254661927156L, 421171648758L, 686353797976L, 1103068603890L, 1749695026860L, 2741188875414L], [1, 19, 190, 1330, 7315, 33649, 134596, 480700, 1562275, 4686825, 13123110, 34597290, 86493225, 206253075, 471435600, 1037158320, 2203961430L, 4537567650L, 9075135300L, 17672631900L, 33578000610L, 62359143990L, 113380261800L, 202112640600L, 353697121050L, 608359048206L, 1029530696964L, 1715884494940L, 2818953098830L, 4568648125690L, 7309837001104L], [1, 20, 210, 1540, 8855, 42504, 177100, 657800, 2220075, 6906900, 20030010, 54627300, 141120525, 347373600, 818809200, 1855967520, 4059928950L, 8597496600L, 17672631900L, 35345263800L, 68923264410L, 131282408400L, 244662670200L, 446775310800L, 800472431850L, 1408831480056L, 2438362177020L, 4154246671960L, 6973199770790L, 11541847896480L, 18851684897584L], [1, 21, 231, 1771, 10626, 53130, 230230, 888030, 3108105, 10015005, 30045015, 84672315, 225792840, 573166440, 1391975640, 3247943160L, 7307872110L, 15905368710L, 33578000610L, 68923264410L, 137846528820L, 269128937220L, 513791607420L, 960566918220L, 1761039350070L, 3169870830126L, 5608233007146L, 9762479679106L, 16735679449896L, 28277527346376L, 47129212243960L], [1, 22, 253, 2024, 12650, 65780, 296010, 1184040, 4292145, 14307150, 44352165, 129024480, 354817320, 927983760, 2319959400L, 5567902560L, 12875774670L, 28781143380L, 62359143990L, 131282408400L, 269128937220L, 538257874440L, 1052049481860L, 2012616400080L, 3773655750150L, 6943526580276L, 12551759587422L, 22314239266528L, 39049918716424L, 67327446062800L, 114456658306760L], [1, 23, 276, 2300, 14950, 80730, 376740, 1560780, 5852925, 20160075, 64512240, 193536720, 548354040, 1476337800, 3796297200L, 9364199760L, 22239974430L, 51021117810L, 113380261800L, 244662670200L, 513791607420L, 1052049481860L, 2104098963720L, 4116715363800L, 7890371113950L, 14833897694226L, 27385657281648L, 49699896548176L, 88749815264600L, 156077261327400L, 270533919634160L], [1, 24, 300, 2600, 17550, 98280, 475020, 2035800, 7888725, 28048800, 92561040, 286097760, 834451800, 2310789600L, 6107086800L, 15471286560L, 37711260990L, 88732378800L, 202112640600L, 446775310800L, 960566918220L, 2012616400080L, 4116715363800L, 8233430727600L, 16123801841550L, 30957699535776L, 58343356817424L, 108043253365600L, 196793068630200L, 352870329957600L, 623404249591760L], [1, 25, 325, 2925, 20475, 118755, 593775, 2629575, 10518300, 38567100, 131128140, 417225900, 1251677700, 3562467300L, 9669554100L, 25140840660L, 62852101650L, 151584480450L, 353697121050L, 800472431850L, 1761039350070L, 3773655750150L, 7890371113950L, 16123801841550L, 32247603683100L, 63205303218876L, 121548660036300L, 229591913401900L, 426384982032100L, 779255311989700L, 1402659561581460L], [1, 26, 351, 3276, 23751, 142506, 736281, 3365856, 13884156, 52451256, 183579396, 600805296, 1852482996, 5414950296L, 15084504396L, 40225345056L, 103077446706L, 254661927156L, 608359048206L, 1408831480056L, 3169870830126L, 6943526580276L, 14833897694226L, 30957699535776L, 63205303218876L, 126410606437752L, 247959266474052L, 477551179875952L, 903936161908052L, 1683191473897752L, 3085851035479212L], [1, 27, 378, 3654, 27405, 169911, 906192, 4272048, 18156204, 70607460, 254186856, 854992152, 2707475148L, 8122425444L, 23206929840L, 63432274896L, 166509721602L, 421171648758L, 1029530696964L, 2438362177020L, 5608233007146L, 12551759587422L, 27385657281648L, 58343356817424L, 121548660036300L, 247959266474052L, 495918532948104L, 973469712824056L, 1877405874732108L, 3560597348629860L, 6646448384109072L], [1, 28, 406, 4060, 31465, 201376, 1107568, 5379616, 23535820, 94143280, 348330136, 1203322288, 3910797436L, 12033222880L, 35240152720L, 98672427616L, 265182149218L, 686353797976L, 1715884494940L, 4154246671960L, 9762479679106L, 22314239266528L, 49699896548176L, 108043253365600L, 229591913401900L, 477551179875952L, 973469712824056L, 1946939425648112L, 3824345300380220L, 7384942649010080L, 14031391033119152L], [1, 29, 435, 4495, 35960, 237336, 1344904, 6724520, 30260340, 124403620, 472733756, 1676056044, 5586853480L, 17620076360L, 52860229080L, 151532656696L, 416714805914L, 1103068603890L, 2818953098830L, 6973199770790L, 16735679449896L, 39049918716424L, 88749815264600L, 196793068630200L, 426384982032100L, 903936161908052L, 1877405874732108L, 3824345300380220L, 7648690600760440L, 15033633249770520L, 29065024282889672L], [1, 30, 465, 4960, 40920, 278256, 1623160, 8347680, 38608020, 163011640, 635745396, 2311801440L, 7898654920L, 25518731280L, 78378960360L, 229911617056L, 646626422970L, 1749695026860L, 4568648125690L, 11541847896480L, 28277527346376L, 67327446062800L, 156077261327400L, 352870329957600L, 779255311989700L, 1683191473897752L, 3560597348629860L, 7384942649010080L, 15033633249770520L, 30067266499541040L, 59132290782430712L], [1, 31, 496, 5456, 46376, 324632, 1947792, 10295472, 48903492, 211915132, 847660528, 3159461968L, 11058116888L, 36576848168L, 114955808528L, 344867425584L, 991493848554L, 2741188875414L, 7309837001104L, 18851684897584L, 47129212243960L, 114456658306760L, 270533919634160L, 623404249591760L, 1402659561581460L, 3085851035479212L, 6646448384109072L, 14031391033119152L, 29065024282889672L, 59132290782430712L, 118264581564861424L], [1, 32, 528, 5984, 52360, 376992, 2324784, 12620256, 61523748, 273438880, 1121099408, 4280561376L, 15338678264L, 51915526432L, 166871334960L, 511738760544L, 1503232609098L, 4244421484512L, 11554258485616L, 30405943383200L, 77535155627160L, 191991813933920L, 462525733568080L, 1085929983159840L, 2488589544741300L, 5574440580220512L, 12220888964329584L, 26252279997448736L, 55317304280338408L, 114449595062769120L, 232714176627630544L]]

with open('count.in') as fi:
    n, m = (int(i) for i in fi.read().split())

with open('count.out', 'w') as fo:
    fo.write(str(res[n-1][m]) + '\n')
