//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

import org.omnetpp.queueing.OFDL;
import org.omnetpp.queueing.Ocombiner;
import org.omnetpp.queueing.Osplitter;
import org.omnetpp.queueing.Oswitch;


network OTSI16TS
{
    @display("bgb=3948,2110;bgg=40");
    submodules:
        ofdl: OFDL {
            @display("p=640,713");
        }
        ofdl1: OFDL {
            @display("p=760,713");
        }
        osplitter: Osplitter {
            @display("p=579,754");
        }
        oswitch: Oswitch {
            @display("p=698,753");
        }
        ofdl2: OFDL {
            @display("p=839,713");
        }
        ofdl3: OFDL {
            @display("p=962,714");
        }
        ofdl4: OFDL {
            @display("p=1041,714");
        }
        oswitch1: Oswitch {
            @display("p=900,754");
        }
        ofdl5: OFDL {
            @display("p=1120,713");
        }
        ofdl6: OFDL {
            @display("p=1199,713");
        }
        oswitch2: Oswitch {
            @display("p=1259,754");
        }
        ofdl7: OFDL {
            @display("p=1321,715");
        }
        ofdl8: OFDL {
            @display("p=1400,715");
        }
        ofdl9: OFDL {
            @display("p=1479,714");
        }
        ofdl10: OFDL {
            @display("p=1558,714");
        }
        ofdl11: OFDL {
            @display("p=1639,713");
        }
        ofdl12: OFDL {
            @display("p=1718,713");
        }
        ofdl13: OFDL {
            @display("p=1797,712");
        }
        ofdl14: OFDL {
            @display("p=1876,712");
        }
        ofdl15: OFDL {
            @display("p=2639,714");
        }
        ofdl16: OFDL {
            @display("p=2718,714");
        }
        ofdl17: OFDL {
            @display("p=2797,713");
        }
        ofdl18: OFDL {
            @display("p=2876,713");
        }
        ofdl19: OFDL {
            @display("p=2957,712");
        }
        ofdl20: OFDL {
            @display("p=3036,712");
        }
        ofdl21: OFDL {
            @display("p=3115,711");
        }
        ofdl22: OFDL {
            @display("p=3194,711");
        }
        ofdl23: OFDL {
            @display("p=2003,715");
        }
        ofdl24: OFDL {
            @display("p=2082,715");
        }
        ofdl25: OFDL {
            @display("p=2161,714");
        }
        ofdl26: OFDL {
            @display("p=2240,714");
        }
        ofdl27: OFDL {
            @display("p=2321,713");
        }
        ofdl28: OFDL {
            @display("p=2400,713");
        }
        ofdl29: OFDL {
            @display("p=2479,712");
        }
        ofdl30: OFDL {
            @display("p=2558,712");
        }
        oswitch3: Oswitch {
            @display("p=1941,754");
        }
        ocombiner: Ocombiner {
            @display("p=3259,753");
        }
        ocombiner1: Ocombiner {
            @display("p=3259,830");
        }
        ofdl31: OFDL {
            @display("p=640,790");
        }
        ofdl32: OFDL {
            @display("p=760,790");
        }
        ofdl33: OFDL {
            @display("p=839,790");
        }
        ofdl34: OFDL {
            @display("p=962,791");
        }
        ofdl35: OFDL {
            @display("p=1041,791");
        }
        ofdl36: OFDL {
            @display("p=1120,790");
        }
        ofdl37: OFDL {
            @display("p=1199,790");
        }
        ofdl38: OFDL {
            @display("p=1321,792");
        }
        ofdl39: OFDL {
            @display("p=1400,792");
        }
        ofdl40: OFDL {
            @display("p=1479,791");
        }
        ofdl41: OFDL {
            @display("p=1558,791");
        }
        ofdl42: OFDL {
            @display("p=1639,790");
        }
        ofdl43: OFDL {
            @display("p=1718,790");
        }
        ofdl44: OFDL {
            @display("p=1797,789");
        }
        ofdl45: OFDL {
            @display("p=1876,789");
        }
        ofdl46: OFDL {
            @display("p=2639,791");
        }
        ofdl47: OFDL {
            @display("p=2718,791");
        }
        ofdl48: OFDL {
            @display("p=2797,790");
        }
        ofdl49: OFDL {
            @display("p=2876,790");
        }
        ofdl50: OFDL {
            @display("p=2957,789");
        }
        ofdl51: OFDL {
            @display("p=3036,789");
        }
        ofdl52: OFDL {
            @display("p=3115,788");
        }
        ofdl53: OFDL {
            @display("p=3194,788");
        }
        ofdl54: OFDL {
            @display("p=2003,792");
        }
        ofdl55: OFDL {
            @display("p=2082,792");
        }
        ofdl56: OFDL {
            @display("p=2161,791");
        }
        ofdl57: OFDL {
            @display("p=2240,791");
        }
        ofdl58: OFDL {
            @display("p=2321,790");
        }
        ofdl59: OFDL {
            @display("p=2400,790");
        }
        ofdl60: OFDL {
            @display("p=2479,789");
        }
        ofdl61: OFDL {
            @display("p=2558,789");
        }
        osplitter1: Osplitter {
            @display("p=579,831");
        }
        oswitch4: Oswitch {
            @display("p=698,830");
        }
        oswitch5: Oswitch {
            @display("p=900,831");
        }
        oswitch6: Oswitch {
            @display("p=1259,831");
        }
        oswitch7: Oswitch {
            @display("p=1941,831");
        }
        ocombiner2: Ocombiner {
            @display("p=3259,911");
        }
        ocombiner3: Ocombiner {
            @display("p=3259,988");
        }
        ofdl62: OFDL {
            @display("p=640,871");
        }
        ofdl63: OFDL {
            @display("p=760,871");
        }
        ofdl64: OFDL {
            @display("p=839,871");
        }
        ofdl65: OFDL {
            @display("p=962,872");
        }
        ofdl66: OFDL {
            @display("p=1041,872");
        }
        ofdl67: OFDL {
            @display("p=1120,871");
        }
        ofdl68: OFDL {
            @display("p=1199,871");
        }
        ofdl69: OFDL {
            @display("p=1321,873");
        }
        ofdl70: OFDL {
            @display("p=1400,873");
        }
        ofdl71: OFDL {
            @display("p=1479,872");
        }
        ofdl72: OFDL {
            @display("p=1558,872");
        }
        ofdl73: OFDL {
            @display("p=1639,871");
        }
        ofdl74: OFDL {
            @display("p=1718,871");
        }
        ofdl75: OFDL {
            @display("p=1797,870");
        }
        ofdl76: OFDL {
            @display("p=1876,870");
        }
        ofdl77: OFDL {
            @display("p=2639,872");
        }
        ofdl78: OFDL {
            @display("p=2718,872");
        }
        ofdl79: OFDL {
            @display("p=2797,871");
        }
        ofdl80: OFDL {
            @display("p=2876,871");
        }
        ofdl81: OFDL {
            @display("p=2957,870");
        }
        ofdl82: OFDL {
            @display("p=3036,870");
        }
        ofdl83: OFDL {
            @display("p=3115,869");
        }
        ofdl84: OFDL {
            @display("p=3194,869");
        }
        ofdl85: OFDL {
            @display("p=2003,873");
        }
        ofdl86: OFDL {
            @display("p=2082,873");
        }
        ofdl87: OFDL {
            @display("p=2161,872");
        }
        ofdl88: OFDL {
            @display("p=2240,872");
        }
        ofdl89: OFDL {
            @display("p=2321,871");
        }
        ofdl90: OFDL {
            @display("p=2400,871");
        }
        ofdl91: OFDL {
            @display("p=2479,870");
        }
        ofdl92: OFDL {
            @display("p=2558,870");
        }
        ofdl93: OFDL {
            @display("p=640,948");
        }
        ofdl94: OFDL {
            @display("p=760,948");
        }
        ofdl95: OFDL {
            @display("p=839,948");
        }
        ofdl96: OFDL {
            @display("p=962,949");
        }
        ofdl97: OFDL {
            @display("p=1041,949");
        }
        ofdl98: OFDL {
            @display("p=1120,948");
        }
        ofdl99: OFDL {
            @display("p=1199,948");
        }
        ofdl100: OFDL {
            @display("p=1321,950");
        }
        ofdl101: OFDL {
            @display("p=1400,950");
        }
        ofdl102: OFDL {
            @display("p=1479,949");
        }
        ofdl103: OFDL {
            @display("p=1558,949");
        }
        ofdl104: OFDL {
            @display("p=1639,948");
        }
        ofdl105: OFDL {
            @display("p=1718,948");
        }
        ofdl106: OFDL {
            @display("p=1797,947");
        }
        ofdl107: OFDL {
            @display("p=1876,947");
        }
        ofdl108: OFDL {
            @display("p=2639,949");
        }
        ofdl109: OFDL {
            @display("p=2718,949");
        }
        ofdl110: OFDL {
            @display("p=2797,948");
        }
        ofdl111: OFDL {
            @display("p=2876,948");
        }
        ofdl112: OFDL {
            @display("p=2957,947");
        }
        ofdl113: OFDL {
            @display("p=3036,947");
        }
        ofdl114: OFDL {
            @display("p=3115,946");
        }
        ofdl115: OFDL {
            @display("p=3194,946");
        }
        ofdl116: OFDL {
            @display("p=2003,950");
        }
        ofdl117: OFDL {
            @display("p=2082,950");
        }
        ofdl118: OFDL {
            @display("p=2161,949");
        }
        ofdl119: OFDL {
            @display("p=2240,949");
        }
        ofdl120: OFDL {
            @display("p=2321,948");
        }
        ofdl121: OFDL {
            @display("p=2400,948");
        }
        ofdl122: OFDL {
            @display("p=2479,947");
        }
        ofdl123: OFDL {
            @display("p=2558,947");
        }
        osplitter2: Osplitter {
            @display("p=579,912");
        }
        osplitter3: Osplitter {
            @display("p=579,989");
        }
        oswitch8: Oswitch {
            @display("p=698,911");
        }
        oswitch9: Oswitch {
            @display("p=900,912");
        }
        oswitch10: Oswitch {
            @display("p=1259,912");
        }
        oswitch11: Oswitch {
            @display("p=1941,912");
        }
        oswitch12: Oswitch {
            @display("p=698,988");
        }
        oswitch13: Oswitch {
            @display("p=900,989");
        }
        oswitch14: Oswitch {
            @display("p=1259,989");
        }
        oswitch15: Oswitch {
            @display("p=1941,989");
        }
        ocombiner4: Ocombiner {
            @display("p=3260,1071");
        }
        ocombiner5: Ocombiner {
            @display("p=3260,1148");
        }
        ocombiner6: Ocombiner {
            @display("p=3260,1229");
        }
        ocombiner7: Ocombiner {
            @display("p=3260,1306");
        }
        ofdl124: OFDL {
            @display("p=641,1031");
        }
        ofdl125: OFDL {
            @display("p=761,1031");
        }
        ofdl126: OFDL {
            @display("p=840,1031");
        }
        ofdl127: OFDL {
            @display("p=963,1032");
        }
        ofdl128: OFDL {
            @display("p=1042,1032");
        }
        ofdl129: OFDL {
            @display("p=1121,1031");
        }
        ofdl130: OFDL {
            @display("p=1200,1031");
        }
        ofdl131: OFDL {
            @display("p=1322,1033");
        }
        ofdl132: OFDL {
            @display("p=1401,1033");
        }
        ofdl133: OFDL {
            @display("p=1480,1032");
        }
        ofdl134: OFDL {
            @display("p=1559,1032");
        }
        ofdl135: OFDL {
            @display("p=1640,1031");
        }
        ofdl136: OFDL {
            @display("p=1719,1031");
        }
        ofdl137: OFDL {
            @display("p=1798,1030");
        }
        ofdl138: OFDL {
            @display("p=1877,1030");
        }
        ofdl139: OFDL {
            @display("p=2640,1032");
        }
        ofdl140: OFDL {
            @display("p=2719,1032");
        }
        ofdl141: OFDL {
            @display("p=2798,1031");
        }
        ofdl142: OFDL {
            @display("p=2877,1031");
        }
        ofdl143: OFDL {
            @display("p=2958,1030");
        }
        ofdl144: OFDL {
            @display("p=3037,1030");
        }
        ofdl145: OFDL {
            @display("p=3116,1029");
        }
        ofdl146: OFDL {
            @display("p=3195,1029");
        }
        ofdl147: OFDL {
            @display("p=2004,1033");
        }
        ofdl148: OFDL {
            @display("p=2083,1033");
        }
        ofdl149: OFDL {
            @display("p=2162,1032");
        }
        ofdl150: OFDL {
            @display("p=2241,1032");
        }
        ofdl151: OFDL {
            @display("p=2322,1031");
        }
        ofdl152: OFDL {
            @display("p=2401,1031");
        }
        ofdl153: OFDL {
            @display("p=2480,1030");
        }
        ofdl154: OFDL {
            @display("p=2559,1030");
        }
        ofdl155: OFDL {
            @display("p=641,1108");
        }
        ofdl156: OFDL {
            @display("p=761,1108");
        }
        ofdl157: OFDL {
            @display("p=840,1108");
        }
        ofdl158: OFDL {
            @display("p=963,1109");
        }
        ofdl159: OFDL {
            @display("p=1042,1109");
        }
        ofdl160: OFDL {
            @display("p=1121,1108");
        }
        ofdl161: OFDL {
            @display("p=1200,1108");
        }
        ofdl162: OFDL {
            @display("p=1322,1110");
        }
        ofdl163: OFDL {
            @display("p=1401,1110");
        }
        ofdl164: OFDL {
            @display("p=1480,1109");
        }
        ofdl165: OFDL {
            @display("p=1559,1109");
        }
        ofdl166: OFDL {
            @display("p=1640,1108");
        }
        ofdl167: OFDL {
            @display("p=1719,1108");
        }
        ofdl168: OFDL {
            @display("p=1798,1107");
        }
        ofdl169: OFDL {
            @display("p=1877,1107");
        }
        ofdl170: OFDL {
            @display("p=2640,1109");
        }
        ofdl171: OFDL {
            @display("p=2719,1109");
        }
        ofdl172: OFDL {
            @display("p=2798,1108");
        }
        ofdl173: OFDL {
            @display("p=2877,1108");
        }
        ofdl174: OFDL {
            @display("p=2958,1107");
        }
        ofdl175: OFDL {
            @display("p=3037,1107");
        }
        ofdl176: OFDL {
            @display("p=3116,1106");
        }
        ofdl177: OFDL {
            @display("p=3195,1106");
        }
        ofdl178: OFDL {
            @display("p=2004,1110");
        }
        ofdl179: OFDL {
            @display("p=2083,1110");
        }
        ofdl180: OFDL {
            @display("p=2162,1109");
        }
        ofdl181: OFDL {
            @display("p=2241,1109");
        }
        ofdl182: OFDL {
            @display("p=2322,1108");
        }
        ofdl183: OFDL {
            @display("p=2401,1108");
        }
        ofdl184: OFDL {
            @display("p=2480,1107");
        }
        ofdl185: OFDL {
            @display("p=2559,1107");
        }
        ofdl186: OFDL {
            @display("p=641,1189");
        }
        ofdl187: OFDL {
            @display("p=761,1189");
        }
        ofdl188: OFDL {
            @display("p=840,1189");
        }
        ofdl189: OFDL {
            @display("p=963,1190");
        }
        ofdl190: OFDL {
            @display("p=1042,1190");
        }
        ofdl191: OFDL {
            @display("p=1121,1189");
        }
        ofdl192: OFDL {
            @display("p=1200,1189");
        }
        ofdl193: OFDL {
            @display("p=1322,1191");
        }
        ofdl194: OFDL {
            @display("p=1401,1191");
        }
        ofdl195: OFDL {
            @display("p=1480,1190");
        }
        ofdl196: OFDL {
            @display("p=1559,1190");
        }
        ofdl197: OFDL {
            @display("p=1640,1189");
        }
        ofdl198: OFDL {
            @display("p=1719,1189");
        }
        ofdl199: OFDL {
            @display("p=1798,1188");
        }
        ofdl200: OFDL {
            @display("p=1877,1188");
        }
        ofdl201: OFDL {
            @display("p=2640,1190");
        }
        ofdl202: OFDL {
            @display("p=2719,1190");
        }
        ofdl203: OFDL {
            @display("p=2798,1189");
        }
        ofdl204: OFDL {
            @display("p=2877,1189");
        }
        ofdl205: OFDL {
            @display("p=2958,1188");
        }
        ofdl206: OFDL {
            @display("p=3037,1188");
        }
        ofdl207: OFDL {
            @display("p=3116,1187");
        }
        ofdl208: OFDL {
            @display("p=3195,1187");
        }
        ofdl209: OFDL {
            @display("p=2004,1191");
        }
        ofdl210: OFDL {
            @display("p=2083,1191");
        }
        ofdl211: OFDL {
            @display("p=2162,1190");
        }
        ofdl212: OFDL {
            @display("p=2241,1190");
        }
        ofdl213: OFDL {
            @display("p=2322,1189");
        }
        ofdl214: OFDL {
            @display("p=2401,1189");
        }
        ofdl215: OFDL {
            @display("p=2480,1188");
        }
        ofdl216: OFDL {
            @display("p=2559,1188");
        }
        ofdl217: OFDL {
            @display("p=641,1266");
        }
        ofdl218: OFDL {
            @display("p=761,1266");
        }
        ofdl219: OFDL {
            @display("p=840,1266");
        }
        ofdl220: OFDL {
            @display("p=963,1267");
        }
        ofdl221: OFDL {
            @display("p=1042,1267");
        }
        ofdl222: OFDL {
            @display("p=1121,1266");
        }
        ofdl223: OFDL {
            @display("p=1200,1266");
        }
        ofdl224: OFDL {
            @display("p=1322,1268");
        }
        ofdl225: OFDL {
            @display("p=1401,1268");
        }
        ofdl226: OFDL {
            @display("p=1480,1267");
        }
        ofdl227: OFDL {
            @display("p=1559,1267");
        }
        ofdl228: OFDL {
            @display("p=1640,1266");
        }
        ofdl229: OFDL {
            @display("p=1719,1266");
        }
        ofdl230: OFDL {
            @display("p=1798,1265");
        }
        ofdl231: OFDL {
            @display("p=1877,1265");
        }
        ofdl232: OFDL {
            @display("p=2640,1267");
        }
        ofdl233: OFDL {
            @display("p=2719,1267");
        }
        ofdl234: OFDL {
            @display("p=2798,1266");
        }
        ofdl235: OFDL {
            @display("p=2877,1266");
        }
        ofdl236: OFDL {
            @display("p=2958,1265");
        }
        ofdl237: OFDL {
            @display("p=3037,1265");
        }
        ofdl238: OFDL {
            @display("p=3116,1264");
        }
        ofdl239: OFDL {
            @display("p=3195,1264");
        }
        ofdl240: OFDL {
            @display("p=2004,1268");
        }
        ofdl241: OFDL {
            @display("p=2083,1268");
        }
        ofdl242: OFDL {
            @display("p=2162,1267");
        }
        ofdl243: OFDL {
            @display("p=2241,1267");
        }
        ofdl244: OFDL {
            @display("p=2322,1266");
        }
        ofdl245: OFDL {
            @display("p=2401,1266");
        }
        ofdl246: OFDL {
            @display("p=2480,1265");
        }
        ofdl247: OFDL {
            @display("p=2559,1265");
        }
        osplitter4: Osplitter {
            @display("p=580,1072");
        }
        osplitter5: Osplitter {
            @display("p=580,1149");
        }
        osplitter6: Osplitter {
            @display("p=580,1230");
        }
        osplitter7: Osplitter {
            @display("p=580,1307");
        }
        oswitch16: Oswitch {
            @display("p=699,1071");
        }
        oswitch17: Oswitch {
            @display("p=901,1072");
        }
        oswitch18: Oswitch {
            @display("p=1260,1072");
        }
        oswitch19: Oswitch {
            @display("p=1942,1072");
        }
        oswitch20: Oswitch {
            @display("p=699,1148");
        }
        oswitch21: Oswitch {
            @display("p=901,1149");
        }
        oswitch22: Oswitch {
            @display("p=1260,1149");
        }
        oswitch23: Oswitch {
            @display("p=1942,1149");
        }
        oswitch24: Oswitch {
            @display("p=699,1229");
        }
        oswitch25: Oswitch {
            @display("p=901,1230");
        }
        oswitch26: Oswitch {
            @display("p=1260,1230");
        }
        oswitch27: Oswitch {
            @display("p=1942,1230");
        }
        oswitch28: Oswitch {
            @display("p=699,1306");
        }
        oswitch29: Oswitch {
            @display("p=901,1307");
        }
        oswitch30: Oswitch {
            @display("p=1260,1307");
        }
        oswitch31: Oswitch {
            @display("p=1942,1307");
        }
        ocombiner8: Ocombiner {
            @display("p=3258,1392");
        }
        ocombiner9: Ocombiner {
            @display("p=3258,1469");
        }
        ocombiner10: Ocombiner {
            @display("p=3258,1550");
        }
        ocombiner11: Ocombiner {
            @display("p=3258,1627");
        }
        ocombiner12: Ocombiner {
            @display("p=3259,1710");
        }
        ocombiner13: Ocombiner {
            @display("p=3259,1787");
        }
        ocombiner14: Ocombiner {
            @display("p=3259,1868");
        }
        ocombiner15: Ocombiner {
            @display("p=3259,1945");
        }
        ofdl248: OFDL {
            @display("p=639,1352");
        }
        ofdl249: OFDL {
            @display("p=759,1352");
        }
        ofdl250: OFDL {
            @display("p=838,1352");
        }
        ofdl251: OFDL {
            @display("p=961,1353");
        }
        ofdl252: OFDL {
            @display("p=1040,1353");
        }
        ofdl253: OFDL {
            @display("p=1119,1352");
        }
        ofdl254: OFDL {
            @display("p=1198,1352");
        }
        ofdl255: OFDL {
            @display("p=1320,1354");
        }
        ofdl256: OFDL {
            @display("p=1399,1354");
        }
        ofdl257: OFDL {
            @display("p=1478,1353");
        }
        ofdl258: OFDL {
            @display("p=1557,1353");
        }
        ofdl259: OFDL {
            @display("p=1638,1352");
        }
        ofdl260: OFDL {
            @display("p=1717,1352");
        }
        ofdl261: OFDL {
            @display("p=1796,1351");
        }
        ofdl262: OFDL {
            @display("p=1875,1351");
        }
        ofdl263: OFDL {
            @display("p=2638,1353");
        }
        ofdl264: OFDL {
            @display("p=2717,1353");
        }
        ofdl265: OFDL {
            @display("p=2796,1352");
        }
        ofdl266: OFDL {
            @display("p=2875,1352");
        }
        ofdl267: OFDL {
            @display("p=2956,1351");
        }
        ofdl268: OFDL {
            @display("p=3035,1351");
        }
        ofdl269: OFDL {
            @display("p=3114,1350");
        }
        ofdl270: OFDL {
            @display("p=3193,1350");
        }
        ofdl271: OFDL {
            @display("p=2002,1354");
        }
        ofdl272: OFDL {
            @display("p=2081,1354");
        }
        ofdl273: OFDL {
            @display("p=2160,1353");
        }
        ofdl274: OFDL {
            @display("p=2239,1353");
        }
        ofdl275: OFDL {
            @display("p=2320,1352");
        }
        ofdl276: OFDL {
            @display("p=2399,1352");
        }
        ofdl277: OFDL {
            @display("p=2478,1351");
        }
        ofdl278: OFDL {
            @display("p=2557,1351");
        }
        ofdl279: OFDL {
            @display("p=639,1429");
        }
        ofdl280: OFDL {
            @display("p=759,1429");
        }
        ofdl281: OFDL {
            @display("p=838,1429");
        }
        ofdl282: OFDL {
            @display("p=961,1430");
        }
        ofdl283: OFDL {
            @display("p=1040,1430");
        }
        ofdl284: OFDL {
            @display("p=1119,1429");
        }
        ofdl285: OFDL {
            @display("p=1198,1429");
        }
        ofdl286: OFDL {
            @display("p=1320,1431");
        }
        ofdl287: OFDL {
            @display("p=1399,1431");
        }
        ofdl288: OFDL {
            @display("p=1478,1430");
        }
        ofdl289: OFDL {
            @display("p=1557,1430");
        }
        ofdl290: OFDL {
            @display("p=1638,1429");
        }
        ofdl291: OFDL {
            @display("p=1717,1429");
        }
        ofdl292: OFDL {
            @display("p=1796,1428");
        }
        ofdl293: OFDL {
            @display("p=1875,1428");
        }
        ofdl294: OFDL {
            @display("p=2638,1430");
        }
        ofdl295: OFDL {
            @display("p=2717,1430");
        }
        ofdl296: OFDL {
            @display("p=2796,1429");
        }
        ofdl297: OFDL {
            @display("p=2875,1429");
        }
        ofdl298: OFDL {
            @display("p=2956,1428");
        }
        ofdl299: OFDL {
            @display("p=3035,1428");
        }
        ofdl300: OFDL {
            @display("p=3114,1427");
        }
        ofdl301: OFDL {
            @display("p=3193,1427");
        }
        ofdl302: OFDL {
            @display("p=2002,1431");
        }
        ofdl303: OFDL {
            @display("p=2081,1431");
        }
        ofdl304: OFDL {
            @display("p=2160,1430");
        }
        ofdl305: OFDL {
            @display("p=2239,1430");
        }
        ofdl306: OFDL {
            @display("p=2320,1429");
        }
        ofdl307: OFDL {
            @display("p=2399,1429");
        }
        ofdl308: OFDL {
            @display("p=2478,1428");
        }
        ofdl309: OFDL {
            @display("p=2557,1428");
        }
        ofdl310: OFDL {
            @display("p=639,1510");
        }
        ofdl311: OFDL {
            @display("p=759,1510");
        }
        ofdl312: OFDL {
            @display("p=838,1510");
        }
        ofdl313: OFDL {
            @display("p=961,1511");
        }
        ofdl314: OFDL {
            @display("p=1040,1511");
        }
        ofdl315: OFDL {
            @display("p=1119,1510");
        }
        ofdl316: OFDL {
            @display("p=1198,1510");
        }
        ofdl317: OFDL {
            @display("p=1320,1512");
        }
        ofdl318: OFDL {
            @display("p=1399,1512");
        }
        ofdl319: OFDL {
            @display("p=1478,1511");
        }
        ofdl320: OFDL {
            @display("p=1557,1511");
        }
        ofdl321: OFDL {
            @display("p=1638,1510");
        }
        ofdl322: OFDL {
            @display("p=1717,1510");
        }
        ofdl323: OFDL {
            @display("p=1796,1509");
        }
        ofdl324: OFDL {
            @display("p=1875,1509");
        }
        ofdl325: OFDL {
            @display("p=2638,1511");
        }
        ofdl326: OFDL {
            @display("p=2717,1511");
        }
        ofdl327: OFDL {
            @display("p=2796,1510");
        }
        ofdl328: OFDL {
            @display("p=2875,1510");
        }
        ofdl329: OFDL {
            @display("p=2956,1509");
        }
        ofdl330: OFDL {
            @display("p=3035,1509");
        }
        ofdl331: OFDL {
            @display("p=3114,1508");
        }
        ofdl332: OFDL {
            @display("p=3193,1508");
        }
        ofdl333: OFDL {
            @display("p=2002,1512");
        }
        ofdl334: OFDL {
            @display("p=2081,1512");
        }
        ofdl335: OFDL {
            @display("p=2160,1511");
        }
        ofdl336: OFDL {
            @display("p=2239,1511");
        }
        ofdl337: OFDL {
            @display("p=2320,1510");
        }
        ofdl338: OFDL {
            @display("p=2399,1510");
        }
        ofdl339: OFDL {
            @display("p=2478,1509");
        }
        ofdl340: OFDL {
            @display("p=2557,1509");
        }
        ofdl341: OFDL {
            @display("p=639,1587");
        }
        ofdl342: OFDL {
            @display("p=759,1587");
        }
        ofdl343: OFDL {
            @display("p=838,1587");
        }
        ofdl344: OFDL {
            @display("p=961,1588");
        }
        ofdl345: OFDL {
            @display("p=1040,1588");
        }
        ofdl346: OFDL {
            @display("p=1119,1587");
        }
        ofdl347: OFDL {
            @display("p=1198,1587");
        }
        ofdl348: OFDL {
            @display("p=1320,1589");
        }
        ofdl349: OFDL {
            @display("p=1399,1589");
        }
        ofdl350: OFDL {
            @display("p=1478,1588");
        }
        ofdl351: OFDL {
            @display("p=1557,1588");
        }
        ofdl352: OFDL {
            @display("p=1638,1587");
        }
        ofdl353: OFDL {
            @display("p=1717,1587");
        }
        ofdl354: OFDL {
            @display("p=1796,1586");
        }
        ofdl355: OFDL {
            @display("p=1875,1586");
        }
        ofdl356: OFDL {
            @display("p=2638,1588");
        }
        ofdl357: OFDL {
            @display("p=2717,1588");
        }
        ofdl358: OFDL {
            @display("p=2796,1587");
        }
        ofdl359: OFDL {
            @display("p=2875,1587");
        }
        ofdl360: OFDL {
            @display("p=2956,1586");
        }
        ofdl361: OFDL {
            @display("p=3035,1586");
        }
        ofdl362: OFDL {
            @display("p=3114,1585");
        }
        ofdl363: OFDL {
            @display("p=3193,1585");
        }
        ofdl364: OFDL {
            @display("p=2002,1589");
        }
        ofdl365: OFDL {
            @display("p=2081,1589");
        }
        ofdl366: OFDL {
            @display("p=2160,1588");
        }
        ofdl367: OFDL {
            @display("p=2239,1588");
        }
        ofdl368: OFDL {
            @display("p=2320,1587");
        }
        ofdl369: OFDL {
            @display("p=2399,1587");
        }
        ofdl370: OFDL {
            @display("p=2478,1586");
        }
        ofdl371: OFDL {
            @display("p=2557,1586");
        }
        ofdl372: OFDL {
            @display("p=640,1670");
        }
        ofdl373: OFDL {
            @display("p=760,1670");
        }
        ofdl374: OFDL {
            @display("p=839,1670");
        }
        ofdl375: OFDL {
            @display("p=962,1671");
        }
        ofdl376: OFDL {
            @display("p=1041,1671");
        }
        ofdl377: OFDL {
            @display("p=1120,1670");
        }
        ofdl378: OFDL {
            @display("p=1199,1670");
        }
        ofdl379: OFDL {
            @display("p=1321,1672");
        }
        ofdl380: OFDL {
            @display("p=1400,1672");
        }
        ofdl381: OFDL {
            @display("p=1479,1671");
        }
        ofdl382: OFDL {
            @display("p=1558,1671");
        }
        ofdl383: OFDL {
            @display("p=1639,1670");
        }
        ofdl384: OFDL {
            @display("p=1718,1670");
        }
        ofdl385: OFDL {
            @display("p=1797,1669");
        }
        ofdl386: OFDL {
            @display("p=1876,1669");
        }
        ofdl387: OFDL {
            @display("p=2639,1671");
        }
        ofdl388: OFDL {
            @display("p=2718,1671");
        }
        ofdl389: OFDL {
            @display("p=2797,1670");
        }
        ofdl390: OFDL {
            @display("p=2876,1670");
        }
        ofdl391: OFDL {
            @display("p=2957,1669");
        }
        ofdl392: OFDL {
            @display("p=3036,1669");
        }
        ofdl393: OFDL {
            @display("p=3115,1668");
        }
        ofdl394: OFDL {
            @display("p=3194,1668");
        }
        ofdl395: OFDL {
            @display("p=2003,1672");
        }
        ofdl396: OFDL {
            @display("p=2082,1672");
        }
        ofdl397: OFDL {
            @display("p=2161,1671");
        }
        ofdl398: OFDL {
            @display("p=2240,1671");
        }
        ofdl399: OFDL {
            @display("p=2321,1670");
        }
        ofdl400: OFDL {
            @display("p=2400,1670");
        }
        ofdl401: OFDL {
            @display("p=2479,1669");
        }
        ofdl402: OFDL {
            @display("p=2558,1669");
        }
        ofdl403: OFDL {
            @display("p=640,1747");
        }
        ofdl404: OFDL {
            @display("p=760,1747");
        }
        ofdl405: OFDL {
            @display("p=839,1747");
        }
        ofdl406: OFDL {
            @display("p=962,1748");
        }
        ofdl407: OFDL {
            @display("p=1041,1748");
        }
        ofdl408: OFDL {
            @display("p=1120,1747");
        }
        ofdl409: OFDL {
            @display("p=1199,1747");
        }
        ofdl410: OFDL {
            @display("p=1321,1749");
        }
        ofdl411: OFDL {
            @display("p=1400,1749");
        }
        ofdl412: OFDL {
            @display("p=1479,1748");
        }
        ofdl413: OFDL {
            @display("p=1558,1748");
        }
        ofdl414: OFDL {
            @display("p=1639,1747");
        }
        ofdl415: OFDL {
            @display("p=1718,1747");
        }
        ofdl416: OFDL {
            @display("p=1797,1746");
        }
        ofdl417: OFDL {
            @display("p=1876,1746");
        }
        ofdl418: OFDL {
            @display("p=2639,1748");
        }
        ofdl419: OFDL {
            @display("p=2718,1748");
        }
        ofdl420: OFDL {
            @display("p=2797,1747");
        }
        ofdl421: OFDL {
            @display("p=2876,1747");
        }
        ofdl422: OFDL {
            @display("p=2957,1746");
        }
        ofdl423: OFDL {
            @display("p=3036,1746");
        }
        ofdl424: OFDL {
            @display("p=3115,1745");
        }
        ofdl425: OFDL {
            @display("p=3194,1745");
        }
        ofdl426: OFDL {
            @display("p=2003,1749");
        }
        ofdl427: OFDL {
            @display("p=2082,1749");
        }
        ofdl428: OFDL {
            @display("p=2161,1748");
        }
        ofdl429: OFDL {
            @display("p=2240,1748");
        }
        ofdl430: OFDL {
            @display("p=2321,1747");
        }
        ofdl431: OFDL {
            @display("p=2400,1747");
        }
        ofdl432: OFDL {
            @display("p=2479,1746");
        }
        ofdl433: OFDL {
            @display("p=2558,1746");
        }
        ofdl434: OFDL {
            @display("p=640,1828");
        }
        ofdl435: OFDL {
            @display("p=760,1828");
        }
        ofdl436: OFDL {
            @display("p=839,1828");
        }
        ofdl437: OFDL {
            @display("p=962,1829");
        }
        ofdl438: OFDL {
            @display("p=1041,1829");
        }
        ofdl439: OFDL {
            @display("p=1120,1828");
        }
        ofdl440: OFDL {
            @display("p=1199,1828");
        }
        ofdl441: OFDL {
            @display("p=1321,1830");
        }
        ofdl442: OFDL {
            @display("p=1400,1830");
        }
        ofdl443: OFDL {
            @display("p=1479,1829");
        }
        ofdl444: OFDL {
            @display("p=1558,1829");
        }
        ofdl445: OFDL {
            @display("p=1639,1828");
        }
        ofdl446: OFDL {
            @display("p=1718,1828");
        }
        ofdl447: OFDL {
            @display("p=1797,1827");
        }
        ofdl448: OFDL {
            @display("p=1876,1827");
        }
        ofdl449: OFDL {
            @display("p=2639,1829");
        }
        ofdl450: OFDL {
            @display("p=2718,1829");
        }
        ofdl451: OFDL {
            @display("p=2797,1828");
        }
        ofdl452: OFDL {
            @display("p=2876,1828");
        }
        ofdl453: OFDL {
            @display("p=2957,1827");
        }
        ofdl454: OFDL {
            @display("p=3036,1827");
        }
        ofdl455: OFDL {
            @display("p=3115,1826");
        }
        ofdl456: OFDL {
            @display("p=3194,1826");
        }
        ofdl457: OFDL {
            @display("p=2003,1830");
        }
        ofdl458: OFDL {
            @display("p=2082,1830");
        }
        ofdl459: OFDL {
            @display("p=2161,1829");
        }
        ofdl460: OFDL {
            @display("p=2240,1829");
        }
        ofdl461: OFDL {
            @display("p=2321,1828");
        }
        ofdl462: OFDL {
            @display("p=2400,1828");
        }
        ofdl463: OFDL {
            @display("p=2479,1827");
        }
        ofdl464: OFDL {
            @display("p=2558,1827");
        }
        ofdl465: OFDL {
            @display("p=640,1905");
        }
        ofdl466: OFDL {
            @display("p=760,1905");
        }
        ofdl467: OFDL {
            @display("p=839,1905");
        }
        ofdl468: OFDL {
            @display("p=962,1906");
        }
        ofdl469: OFDL {
            @display("p=1041,1906");
        }
        ofdl470: OFDL {
            @display("p=1120,1905");
        }
        ofdl471: OFDL {
            @display("p=1199,1905");
        }
        ofdl472: OFDL {
            @display("p=1321,1907");
        }
        ofdl473: OFDL {
            @display("p=1400,1907");
        }
        ofdl474: OFDL {
            @display("p=1479,1906");
        }
        ofdl475: OFDL {
            @display("p=1558,1906");
        }
        ofdl476: OFDL {
            @display("p=1639,1905");
        }
        ofdl477: OFDL {
            @display("p=1718,1905");
        }
        ofdl478: OFDL {
            @display("p=1797,1904");
        }
        ofdl479: OFDL {
            @display("p=1876,1904");
        }
        ofdl480: OFDL {
            @display("p=2639,1906");
        }
        ofdl481: OFDL {
            @display("p=2718,1906");
        }
        ofdl482: OFDL {
            @display("p=2797,1905");
        }
        ofdl483: OFDL {
            @display("p=2876,1905");
        }
        ofdl484: OFDL {
            @display("p=2957,1904");
        }
        ofdl485: OFDL {
            @display("p=3036,1904");
        }
        ofdl486: OFDL {
            @display("p=3115,1903");
        }
        ofdl487: OFDL {
            @display("p=3194,1903");
        }
        ofdl488: OFDL {
            @display("p=2003,1907");
        }
        ofdl489: OFDL {
            @display("p=2082,1907");
        }
        ofdl490: OFDL {
            @display("p=2161,1906");
        }
        ofdl491: OFDL {
            @display("p=2240,1906");
        }
        ofdl492: OFDL {
            @display("p=2321,1905");
        }
        ofdl493: OFDL {
            @display("p=2400,1905");
        }
        ofdl494: OFDL {
            @display("p=2479,1904");
        }
        ofdl495: OFDL {
            @display("p=2558,1904");
        }
        osplitter8: Osplitter {
            @display("p=578,1393");
        }
        osplitter9: Osplitter {
            @display("p=578,1470");
        }
        osplitter10: Osplitter {
            @display("p=578,1551");
        }
        osplitter11: Osplitter {
            @display("p=578,1628");
        }
        osplitter12: Osplitter {
            @display("p=579,1711");
        }
        osplitter13: Osplitter {
            @display("p=579,1788");
        }
        osplitter14: Osplitter {
            @display("p=579,1869");
        }
        osplitter15: Osplitter {
            @display("p=579,1946");
        }
        oswitch32: Oswitch {
            @display("p=697,1392");
        }
        oswitch33: Oswitch {
            @display("p=899,1393");
        }
        oswitch34: Oswitch {
            @display("p=1258,1393");
        }
        oswitch35: Oswitch {
            @display("p=1940,1393");
        }
        oswitch36: Oswitch {
            @display("p=697,1469");
        }
        oswitch37: Oswitch {
            @display("p=899,1470");
        }
        oswitch38: Oswitch {
            @display("p=1258,1470");
        }
        oswitch39: Oswitch {
            @display("p=1940,1470");
        }
        oswitch40: Oswitch {
            @display("p=697,1550");
        }
        oswitch41: Oswitch {
            @display("p=899,1551");
        }
        oswitch42: Oswitch {
            @display("p=1258,1551");
        }
        oswitch43: Oswitch {
            @display("p=1940,1551");
        }
        oswitch44: Oswitch {
            @display("p=697,1627");
        }
        oswitch45: Oswitch {
            @display("p=899,1628");
        }
        oswitch46: Oswitch {
            @display("p=1258,1628");
        }
        oswitch47: Oswitch {
            @display("p=1940,1628");
        }
        oswitch48: Oswitch {
            @display("p=698,1710");
        }
        oswitch49: Oswitch {
            @display("p=900,1711");
        }
        oswitch50: Oswitch {
            @display("p=1259,1711");
        }
        oswitch51: Oswitch {
            @display("p=1941,1711");
        }
        oswitch52: Oswitch {
            @display("p=698,1787");
        }
        oswitch53: Oswitch {
            @display("p=900,1788");
        }
        oswitch54: Oswitch {
            @display("p=1259,1788");
        }
        oswitch55: Oswitch {
            @display("p=1941,1788");
        }
        oswitch56: Oswitch {
            @display("p=698,1868");
        }
        oswitch57: Oswitch {
            @display("p=900,1869");
        }
        oswitch58: Oswitch {
            @display("p=1259,1869");
        }
        oswitch59: Oswitch {
            @display("p=1941,1869");
        }
        oswitch60: Oswitch {
            @display("p=698,1945");
        }
        oswitch61: Oswitch {
            @display("p=900,1946");
        }
        oswitch62: Oswitch {
            @display("p=1259,1946");
        }
        oswitch63: Oswitch {
            @display("p=1941,1946");
        }
    connections:
        osplitter.out[0] --> ofdl.in;
        ofdl.out --> oswitch.in[0];
        osplitter.out[1] --> oswitch.in[1];
        oswitch.out[0] --> ofdl1.in;
        ofdl1.out --> ofdl2.in;
        ofdl2.out --> oswitch1.in[0];
        oswitch.out[1] --> oswitch1.in[1];
        oswitch1.out[0] --> ofdl3.in;
        ofdl3.out --> ofdl4.in;
        ofdl4.out --> ofdl5.in;
        ofdl5.out --> ofdl6.in;
        ofdl6.out --> oswitch2.in[0];
        oswitch1.out[1] --> oswitch2.in[1];
        oswitch2.out[0] --> ofdl7.in;
        ofdl7.out --> ofdl8.in;
        ofdl8.out --> ofdl9.in;
        ofdl9.out --> ofdl10.in;
        ofdl10.out --> ofdl11.in;
        ofdl11.out --> ofdl12.in;
        ofdl12.out --> ofdl13.in;
        ofdl13.out --> ofdl14.in;
        ofdl14.out --> oswitch3.in[0];
        oswitch2.out[1] --> oswitch3.in[1];
        oswitch3.out[0] --> ofdl23.in;
        ofdl23.out --> ofdl24.in;
        ofdl24.out --> ofdl25.in;
        ofdl25.out --> ofdl26.in;
        ofdl26.out --> ofdl27.in;
        ofdl27.out --> ofdl28.in;
        ofdl28.out --> ofdl29.in;
        ofdl29.out --> ofdl30.in;
        ofdl30.out --> ofdl15.in;
        ofdl15.out --> ofdl16.in;
        ofdl16.out --> ofdl17.in;
        ofdl17.out --> ofdl18.in;
        ofdl18.out --> ofdl19.in;
        ofdl19.out --> ofdl20.in;
        ofdl20.out --> ofdl21.in;
        ofdl21.out --> ofdl22.in;
        ofdl22.out --> ocombiner.in[0];
        oswitch3.out[1] --> ocombiner.in[1];
        oswitch7.out[0] --> ofdl54.in;
        oswitch7.out[1] --> ocombiner1.in[1];
        ofdl58.out --> ofdl59.in;
        ofdl57.out --> ofdl58.in;
        ofdl34.out --> ofdl35.in;
        ofdl39.out --> ofdl40.in;
        oswitch5.out[0] --> ofdl34.in;
        oswitch5.out[1] --> oswitch6.in[1];
        ofdl51.out --> ofdl52.in;
        ofdl46.out --> ofdl47.in;
        ofdl43.out --> ofdl44.in;
        ofdl56.out --> ofdl57.in;
        ofdl52.out --> ofdl53.in;
        ofdl41.out --> ofdl42.in;
        oswitch4.out[0] --> ofdl32.in;
        oswitch4.out[1] --> oswitch5.in[1];
        ofdl54.out --> ofdl55.in;
        ofdl59.out --> ofdl60.in;
        ofdl42.out --> ofdl43.in;
        oswitch6.out[0] --> ofdl38.in;
        oswitch6.out[1] --> oswitch7.in[1];
        ofdl60.out --> ofdl61.in;
        ofdl61.out --> ofdl46.in;
        ofdl38.out --> ofdl39.in;
        ofdl44.out --> ofdl45.in;
        ofdl31.out --> oswitch4.in[0];
        ofdl49.out --> ofdl50.in;
        ofdl55.out --> ofdl56.in;
        ofdl32.out --> ofdl33.in;
        ofdl36.out --> ofdl37.in;
        ofdl45.out --> oswitch7.in[0];
        ofdl40.out --> ofdl41.in;
        osplitter1.out[0] --> ofdl31.in;
        osplitter1.out[1] --> oswitch4.in[1];
        ofdl50.out --> ofdl51.in;
        ofdl48.out --> ofdl49.in;
        ofdl35.out --> ofdl36.in;
        ofdl53.out --> ocombiner1.in[0];
        ofdl37.out --> oswitch6.in[0];
        ofdl33.out --> oswitch5.in[0];
        ofdl47.out --> ofdl48.in;
        oswitch11.out[0] --> ofdl85.in;
        oswitch11.out[1] --> ocombiner2.in[1];
        ofdl65.out --> ofdl66.in;
        ofdl88.out --> ofdl89.in;
        ofdl89.out --> ofdl90.in;
        oswitch9.out[0] --> ofdl65.in;
        oswitch9.out[1] --> oswitch10.in[1];
        ofdl93.out --> oswitch12.in[0];
        ofdl119.out --> ofdl120.in;
        ofdl87.out --> ofdl88.in;
        ofdl72.out --> ofdl73.in;
        ofdl118.out --> ofdl119.in;
        ofdl112.out --> ofdl113.in;
        ofdl107.out --> oswitch15.in[0];
        osplitter3.out[0] --> ofdl93.in;
        osplitter3.out[1] --> oswitch12.in[1];
        ofdl105.out --> ofdl106.in;
        ofdl114.out --> ofdl115.in;
        ofdl91.out --> ofdl92.in;
        ofdl92.out --> ofdl77.in;
        ofdl111.out --> ofdl112.in;
        ofdl69.out --> ofdl70.in;
        ofdl108.out --> ofdl109.in;
        ofdl62.out --> oswitch8.in[0];
        ofdl97.out --> ofdl98.in;
        ofdl86.out --> ofdl87.in;
        ofdl113.out --> ofdl114.in;
        ofdl63.out --> ofdl64.in;
        ofdl67.out --> ofdl68.in;
        ofdl71.out --> ofdl72.in;
        ofdl101.out --> ofdl102.in;
        ofdl122.out --> ofdl123.in;
        ofdl116.out --> ofdl117.in;
        ofdl104.out --> ofdl105.in;
        ofdl81.out --> ofdl82.in;
        ofdl79.out --> ofdl80.in;
        ofdl94.out --> ofdl95.in;
        oswitch12.out[0] --> ofdl94.in;
        oswitch12.out[1] --> oswitch13.in[1];
        ofdl123.out --> ofdl108.in;
        ofdl109.out --> ofdl110.in;
        ofdl115.out --> ocombiner3.in[0];
        ofdl103.out --> ofdl104.in;
        ofdl117.out --> ofdl118.in;
        ofdl78.out --> ofdl79.in;
        ofdl64.out --> oswitch9.in[0];
        ofdl121.out --> ofdl122.in;
        ofdl98.out --> ofdl99.in;
        ofdl70.out --> ofdl71.in;
        ofdl77.out --> ofdl78.in;
        ofdl82.out --> ofdl83.in;
        ofdl74.out --> ofdl75.in;
        ofdl83.out --> ofdl84.in;
        oswitch8.out[0] --> ofdl63.in;
        oswitch8.out[1] --> oswitch9.in[1];
        ofdl85.out --> ofdl86.in;
        ofdl90.out --> ofdl91.in;
        ofdl100.out --> ofdl101.in;
        ofdl73.out --> ofdl74.in;
        oswitch10.out[0] --> ofdl69.in;
        oswitch10.out[1] --> oswitch11.in[1];
        ofdl102.out --> ofdl103.in;
        ofdl110.out --> ofdl111.in;
        oswitch13.out[0] --> ofdl96.in;
        oswitch13.out[1] --> oswitch14.in[1];
        ofdl99.out --> oswitch14.in[0];
        ofdl75.out --> ofdl76.in;
        ofdl80.out --> ofdl81.in;
        ofdl96.out --> ofdl97.in;
        ofdl76.out --> oswitch11.in[0];
        oswitch14.out[0] --> ofdl100.in;
        oswitch14.out[1] --> oswitch15.in[1];
        osplitter2.out[0] --> ofdl62.in;
        osplitter2.out[1] --> oswitch8.in[1];
        ofdl106.out --> ofdl107.in;
        ofdl95.out --> oswitch13.in[0];
        ofdl66.out --> ofdl67.in;
        ofdl84.out --> ocombiner2.in[0];
        oswitch15.out[0] --> ofdl116.in;
        oswitch15.out[1] --> ocombiner3.in[1];
        ofdl120.out --> ofdl121.in;
        ofdl68.out --> oswitch10.in[0];
        ofdl208.out --> ocombiner6.in[0];
        ofdl188.out --> oswitch25.in[0];
        ofdl228.out --> ofdl229.in;
        ofdl151.out --> ofdl152.in;
        ofdl150.out --> ofdl151.in;
        ofdl244.out --> ofdl245.in;
        ofdl220.out --> ofdl221.in;
        ofdl214.out --> ofdl215.in;
        oswitch17.out[0] --> ofdl127.in;
        oswitch17.out[1] --> oswitch18.in[1];
        ofdl155.out --> oswitch20.in[0];
        ofdl181.out --> ofdl182.in;
        ofdl149.out --> ofdl150.in;
        ofdl235.out --> ofdl236.in;
        ofdl134.out --> ofdl135.in;
        ofdl222.out --> ofdl223.in;
        ofdl209.out --> ofdl210.in;
        ofdl210.out --> ofdl211.in;
        ofdl201.out --> ofdl202.in;
        ofdl227.out --> ofdl228.in;
        ofdl225.out --> ofdl226.in;
        ofdl242.out --> ofdl243.in;
        ofdl231.out --> oswitch31.in[0];
        ofdl169.out --> oswitch23.in[0];
        ofdl195.out --> ofdl196.in;
        osplitter5.out[0] --> ofdl155.in;
        osplitter5.out[1] --> oswitch20.in[1];
        ofdl176.out --> ofdl177.in;
        oswitch28.out[0] --> ofdl218.in;
        oswitch28.out[1] --> oswitch29.in[1];
        ofdl124.out --> oswitch16.in[0];
        ofdl159.out --> ofdl160.in;
        ofdl186.out --> oswitch24.in[0];
        ofdl148.out --> ofdl149.in;
        ofdl202.out --> ofdl203.in;
        ofdl184.out --> ofdl185.in;
        ofdl143.out --> ofdl144.in;
        ofdl166.out --> ofdl167.in;
        ofdl178.out --> ofdl179.in;
        ofdl141.out --> ofdl142.in;
        ofdl243.out --> ofdl244.in;
        ofdl226.out --> ofdl227.in;
        oswitch20.out[0] --> ofdl156.in;
        oswitch20.out[1] --> oswitch21.in[1];
        ofdl206.out --> ofdl207.in;
        ofdl171.out --> ofdl172.in;
        ofdl177.out --> ocombiner5.in[0];
        ofdl216.out --> ofdl201.in;
        ofdl140.out --> ofdl141.in;
        ofdl179.out --> ofdl180.in;
        ofdl183.out --> ofdl184.in;
        ofdl160.out --> ofdl161.in;
        ofdl204.out --> ofdl205.in;
        ofdl230.out --> ofdl231.in;
        ofdl132.out --> ofdl133.in;
        ofdl199.out --> ofdl200.in;
        ofdl218.out --> ofdl219.in;
        ofdl213.out --> ofdl214.in;
        ofdl144.out --> ofdl145.in;
        ofdl139.out --> ofdl140.in;
        ofdl136.out --> ofdl137.in;
        ofdl193.out --> ofdl194.in;
        ofdl238.out --> ofdl239.in;
        ofdl207.out --> ofdl208.in;
        ofdl236.out --> ofdl237.in;
        ofdl241.out --> ofdl242.in;
        oswitch29.out[0] --> ofdl220.in;
        oswitch29.out[1] --> oswitch30.in[1];
        ofdl162.out --> ofdl163.in;
        oswitch26.out[0] --> ofdl193.in;
        oswitch26.out[1] --> oswitch27.in[1];
        ofdl135.out --> ofdl136.in;
        ofdl200.out --> oswitch27.in[0];
        ofdl212.out --> ofdl213.in;
        ofdl196.out --> ofdl197.in;
        oswitch21.out[0] --> ofdl158.in;
        oswitch21.out[1] --> oswitch22.in[1];
        ofdl190.out --> ofdl191.in;
        ofdl233.out --> ofdl234.in;
        ofdl137.out --> ofdl138.in;
        ofdl187.out --> ofdl188.in;
        oswitch25.out[0] --> ofdl189.in;
        oswitch25.out[1] --> oswitch26.in[1];
        ofdl158.out --> ofdl159.in;
        ofdl142.out --> ofdl143.in;
        ofdl138.out --> oswitch19.in[0];
        ofdl205.out --> ofdl206.in;
        ofdl189.out --> ofdl190.in;
        osplitter4.out[0] --> ofdl124.in;
        osplitter4.out[1] --> oswitch16.in[1];
        ofdl168.out --> ofdl169.in;
        ofdl237.out --> ofdl238.in;
        ofdl221.out --> ofdl222.in;
        oswitch31.out[0] --> ofdl240.in;
        oswitch31.out[1] --> ocombiner7.in[1];
        osplitter6.out[0] --> ofdl186.in;
        osplitter6.out[1] --> oswitch24.in[1];
        oswitch30.out[0] --> ofdl224.in;
        oswitch30.out[1] --> oswitch31.in[1];
        ofdl128.out --> ofdl129.in;
        ofdl146.out --> ocombiner4.in[0];
        ofdl191.out --> ofdl192.in;
        oswitch23.out[0] --> ofdl178.in;
        oswitch23.out[1] --> ocombiner5.in[1];
        oswitch19.out[0] --> ofdl147.in;
        oswitch19.out[1] --> ocombiner4.in[1];
        ofdl127.out --> ofdl128.in;
        ofdl192.out --> oswitch26.in[0];
        ofdl246.out --> ofdl247.in;
        ofdl232.out --> ofdl233.in;
        ofdl180.out --> ofdl181.in;
        ofdl224.out --> ofdl225.in;
        ofdl174.out --> ofdl175.in;
        ofdl167.out --> ofdl168.in;
        ofdl153.out --> ofdl154.in;
        ofdl154.out --> ofdl139.in;
        ofdl173.out --> ofdl174.in;
        ofdl131.out --> ofdl132.in;
        osplitter7.out[0] --> ofdl217.in;
        osplitter7.out[1] --> oswitch28.in[1];
        ofdl170.out --> ofdl171.in;
        ofdl247.out --> ofdl232.in;
        ofdl245.out --> ofdl246.in;
        ofdl194.out --> ofdl195.in;
        ofdl125.out --> ofdl126.in;
        ofdl175.out --> ofdl176.in;
        ofdl129.out --> ofdl130.in;
        ofdl163.out --> ofdl164.in;
        ofdl133.out --> ofdl134.in;
        ofdl229.out --> ofdl230.in;
        ofdl211.out --> ofdl212.in;
        ofdl203.out --> ofdl204.in;
        ofdl156.out --> ofdl157.in;
        ofdl185.out --> ofdl170.in;
        ofdl215.out --> ofdl216.in;
        ofdl165.out --> ofdl166.in;
        ofdl126.out --> oswitch17.in[0];
        ofdl198.out --> ofdl199.in;
        ofdl223.out --> oswitch30.in[0];
        ofdl239.out --> ocombiner7.in[0];
        ofdl145.out --> ofdl146.in;
        oswitch27.out[0] --> ofdl209.in;
        oswitch27.out[1] --> ocombiner6.in[1];
        oswitch24.out[0] --> ofdl187.in;
        oswitch24.out[1] --> oswitch25.in[1];
        oswitch16.out[0] --> ofdl125.in;
        oswitch16.out[1] --> oswitch17.in[1];
        ofdl147.out --> ofdl148.in;
        ofdl152.out --> ofdl153.in;
        ofdl240.out --> ofdl241.in;
        oswitch18.out[0] --> ofdl131.in;
        oswitch18.out[1] --> oswitch19.in[1];
        ofdl164.out --> ofdl165.in;
        ofdl172.out --> ofdl173.in;
        ofdl161.out --> oswitch22.in[0];
        ofdl234.out --> ofdl235.in;
        oswitch22.out[0] --> ofdl162.in;
        oswitch22.out[1] --> oswitch23.in[1];
        ofdl157.out --> oswitch21.in[0];
        ofdl217.out --> oswitch28.in[0];
        ofdl197.out --> ofdl198.in;
        ofdl219.out --> oswitch29.in[0];
        ofdl130.out --> oswitch18.in[0];
        ofdl182.out --> ofdl183.in;
        ofdl312.out --> oswitch41.in[0];
        ofdl275.out --> ofdl276.in;
        ofdl352.out --> ofdl353.in;
        ofdl368.out --> ofdl369.in;
        ofdl344.out --> ofdl345.in;
        ofdl459.out --> ofdl460.in;
        ofdl338.out --> ofdl339.in;
        oswitch33.out[0] --> ofdl251.in;
        oswitch33.out[1] --> oswitch34.in[1];
        ofdl279.out --> oswitch36.in[0];
        ofdl305.out --> ofdl306.in;
        ofdl472.out --> ofdl473.in;
        ofdl359.out --> ofdl360.in;
        ofdl258.out --> ofdl259.in;
        ofdl437.out --> ofdl438.in;
        oswitch56.out[0] --> ofdl435.in;
        oswitch56.out[1] --> oswitch57.in[1];
        ofdl351.out --> ofdl352.in;
        ofdl319.out --> ofdl320.in;
        ofdl293.out --> oswitch39.in[0];
        ofdl355.out --> oswitch47.in[0];
        osplitter9.out[0] --> ofdl279.in;
        osplitter9.out[1] --> oswitch36.in[1];
        ofdl448.out --> oswitch59.in[0];
        ofdl300.out --> ofdl301.in;
        ofdl388.out --> ofdl389.in;
        ofdl389.out --> ofdl390.in;
        ofdl283.out --> ofdl284.in;
        ofdl326.out --> ofdl327.in;
        ofdl391.out --> ofdl392.in;
        oswitch57.out[0] --> ofdl437.in;
        oswitch57.out[1] --> oswitch58.in[1];
        ofdl308.out --> ofdl309.in;
        ofdl302.out --> ofdl303.in;
        ofdl267.out --> ofdl268.in;
        ofdl390.out --> ofdl391.in;
        ofdl367.out --> ofdl368.in;
        ofdl350.out --> ofdl351.in;
        oswitch36.out[0] --> ofdl280.in;
        oswitch36.out[1] --> oswitch37.in[1];
        ofdl330.out --> ofdl331.in;
        ofdl295.out --> ofdl296.in;
        ofdl387.out --> ofdl388.in;
        ofdl468.out --> ofdl469.in;
        ofdl301.out --> ocombiner9.in[0];
        ofdl340.out --> ofdl325.in;
        ofdl303.out --> ofdl304.in;
        ofdl264.out --> ofdl265.in;
        ofdl307.out --> ofdl308.in;
        ofdl284.out --> ofdl285.in;
        osplitter14.out[0] --> ofdl434.in;
        osplitter14.out[1] --> oswitch56.in[1];
        ofdl418.out --> ofdl419.in;
        ofdl256.out --> ofdl257.in;
        ofdl409.out --> oswitch54.in[0];
        ofdl268.out --> ofdl269.in;
        ofdl317.out --> ofdl318.in;
        ofdl331.out --> ofdl332.in;
        oswitch55.out[0] --> ofdl426.in;
        oswitch55.out[1] --> ocombiner13.in[1];
        ofdl436.out --> oswitch57.in[0];
        ofdl393.out --> ofdl394.in;
        ofdl452.out --> ofdl453.in;
        ofdl286.out --> ofdl287.in;
        oswitch42.out[0] --> ofdl317.in;
        oswitch42.out[1] --> oswitch43.in[1];
        ofdl379.out --> ofdl380.in;
        ofdl324.out --> oswitch43.in[0];
        ofdl485.out --> ofdl486.in;
        ofdl458.out --> ofdl459.in;
        oswitch37.out[0] --> ofdl282.in;
        oswitch37.out[1] --> oswitch38.in[1];
        ofdl314.out --> ofdl315.in;
        oswitch61.out[0] --> ofdl468.in;
        oswitch61.out[1] --> oswitch62.in[1];
        ofdl486.out --> ofdl487.in;
        oswitch41.out[0] --> ofdl313.in;
        oswitch41.out[1] --> oswitch42.in[1];
        ofdl262.out --> oswitch35.in[0];
        oswitch51.out[0] --> ofdl395.in;
        oswitch51.out[1] --> ocombiner12.in[1];
        osplitter8.out[0] --> ofdl248.in;
        osplitter8.out[1] --> oswitch32.in[1];
        ofdl397.out --> ofdl398.in;
        ofdl450.out --> ofdl451.in;
        ofdl446.out --> ofdl447.in;
        ofdl361.out --> ofdl362.in;
        osplitter10.out[0] --> ofdl310.in;
        osplitter10.out[1] --> oswitch40.in[1];
        oswitch46.out[0] --> ofdl348.in;
        oswitch46.out[1] --> oswitch47.in[1];
        ofdl420.out --> ofdl421.in;
        oswitch39.out[0] --> ofdl302.in;
        oswitch39.out[1] --> ocombiner9.in[1];
        ofdl403.out --> oswitch52.in[0];
        oswitch35.out[0] --> ofdl271.in;
        oswitch35.out[1] --> ocombiner8.in[1];
        ofdl251.out --> ofdl252.in;
        ofdl370.out --> ofdl371.in;
        ofdl383.out --> ofdl384.in;
        ofdl444.out --> ofdl445.in;
        ofdl408.out --> ofdl409.in;
        oswitch59.out[0] --> ofdl457.in;
        oswitch59.out[1] --> ocombiner14.in[1];
        ofdl454.out --> ofdl455.in;
        ofdl373.out --> ofdl374.in;
        ofdl298.out --> ofdl299.in;
        osplitter12.out[0] --> ofdl372.in;
        osplitter12.out[1] --> oswitch48.in[1];
        ofdl489.out --> ofdl490.in;
        ofdl467.out --> oswitch61.in[0];
        ofdl291.out --> ofdl292.in;
        ofdl255.out --> ofdl256.in;
        osplitter11.out[0] --> ofdl341.in;
        osplitter11.out[1] --> oswitch44.in[1];
        ofdl369.out --> ofdl370.in;
        ofdl371.out --> ofdl356.in;
        osplitter13.out[0] --> ofdl403.in;
        osplitter13.out[1] --> oswitch52.in[1];
        ofdl479.out --> oswitch63.in[0];
        ofdl287.out --> ofdl288.in;
        ofdl463.out --> ofdl464.in;
        ofdl335.out --> ofdl336.in;
        ofdl470.out --> ofdl471.in;
        oswitch58.out[0] --> ofdl441.in;
        oswitch58.out[1] --> oswitch59.in[1];
        oswitch48.out[0] --> ofdl373.in;
        oswitch48.out[1] --> oswitch49.in[1];
        ofdl327.out --> ofdl328.in;
        ofdl280.out --> ofdl281.in;
        ofdl426.out --> ofdl427.in;
        ofdl413.out --> ofdl414.in;
        ofdl309.out --> ofdl294.in;
        ofdl484.out --> ofdl485.in;
        ofdl382.out --> ofdl383.in;
        ofdl289.out --> ofdl290.in;
        ofdl250.out --> oswitch33.in[0];
        ofdl322.out --> ofdl323.in;
        ofdl464.out --> ofdl449.in;
        ofdl492.out --> ofdl493.in;
        oswitch54.out[0] --> ofdl410.in;
        oswitch54.out[1] --> oswitch55.in[1];
        ofdl347.out --> oswitch46.in[0];
        ofdl269.out --> ofdl270.in;
        ofdl375.out --> ofdl376.in;
        oswitch32.out[0] --> ofdl249.in;
        oswitch32.out[1] --> oswitch33.in[1];
        ofdl276.out --> ofdl277.in;
        ofdl374.out --> oswitch49.in[0];
        oswitch60.out[0] --> ofdl466.in;
        oswitch60.out[1] --> oswitch61.in[1];
        ofdl364.out --> ofdl365.in;
        oswitch34.out[0] --> ofdl255.in;
        oswitch34.out[1] --> oswitch35.in[1];
        ofdl439.out --> ofdl440.in;
        ofdl447.out --> ofdl448.in;
        ofdl296.out --> ofdl297.in;
        ofdl442.out --> ofdl443.in;
        ofdl462.out --> ofdl463.in;
        oswitch52.out[0] --> ofdl404.in;
        oswitch52.out[1] --> oswitch53.in[1];
        ofdl475.out --> ofdl476.in;
        ofdl358.out --> ofdl359.in;
        ofdl469.out --> ofdl470.in;
        ofdl416.out --> ofdl417.in;
        osplitter15.out[0] --> ofdl465.in;
        osplitter15.out[1] --> oswitch60.in[1];
        ofdl488.out --> ofdl489.in;
        ofdl396.out --> ofdl397.in;
        ofdl466.out --> ofdl467.in;
        ofdl438.out --> ofdl439.in;
        oswitch49.out[0] --> ofdl375.in;
        oswitch49.out[1] --> oswitch50.in[1];
        ofdl321.out --> ofdl322.in;
        ofdl343.out --> oswitch45.in[0];
        ofdl381.out --> ofdl382.in;
        ofdl306.out --> ofdl307.in;
        ofdl254.out --> oswitch34.in[0];
        ofdl332.out --> ocombiner10.in[0];
        ofdl274.out --> ofdl275.in;
        ofdl428.out --> ofdl429.in;
        ofdl460.out --> ofdl461.in;
        ofdl430.out --> ofdl431.in;
        ofdl273.out --> ofdl274.in;
        ofdl346.out --> ofdl347.in;
        ofdl333.out --> ofdl334.in;
        ofdl401.out --> ofdl402.in;
        ofdl325.out --> ofdl326.in;
        ofdl334.out --> ofdl335.in;
        ofdl392.out --> ofdl393.in;
        ofdl435.out --> ofdl436.in;
        ofdl349.out --> ofdl350.in;
        ofdl366.out --> ofdl367.in;
        ofdl411.out --> ofdl412.in;
        ofdl421.out --> ofdl422.in;
        oswitch44.out[0] --> ofdl342.in;
        oswitch44.out[1] --> oswitch45.in[1];
        ofdl248.out --> oswitch32.in[0];
        ofdl453.out --> ofdl454.in;
        ofdl310.out --> oswitch40.in[0];
        ofdl482.out --> ofdl483.in;
        ofdl272.out --> ofdl273.in;
        ofdl380.out --> ofdl381.in;
        ofdl404.out --> ofdl405.in;
        ofdl290.out --> ofdl291.in;
        ofdl465.out --> oswitch60.in[0];
        ofdl434.out --> oswitch56.in[0];
        ofdl407.out --> ofdl408.in;
        ofdl431.out --> ofdl432.in;
        ofdl265.out --> ofdl266.in;
        ofdl487.out --> ocombiner15.in[0];
        ofdl372.out --> oswitch48.in[0];
        ofdl328.out --> ofdl329.in;
        ofdl354.out --> ofdl355.in;
        ofdl417.out --> oswitch55.in[0];
        ofdl323.out --> ofdl324.in;
        ofdl263.out --> ofdl264.in;
        ofdl337.out --> ofdl338.in;
        ofdl342.out --> ofdl343.in;
        ofdl260.out --> ofdl261.in;
        ofdl445.out --> ofdl446.in;
        ofdl362.out --> ofdl363.in;
        ofdl360.out --> ofdl361.in;
        ofdl365.out --> ofdl366.in;
        oswitch45.out[0] --> ofdl344.in;
        oswitch45.out[1] --> oswitch46.in[1];
        ofdl455.out --> ofdl456.in;
        ofdl259.out --> ofdl260.in;
        ofdl336.out --> ofdl337.in;
        ofdl320.out --> ofdl321.in;
        ofdl378.out --> oswitch50.in[0];
        ofdl384.out --> ofdl385.in;
        ofdl483.out --> ofdl484.in;
        ofdl494.out --> ofdl495.in;
        ofdl261.out --> ofdl262.in;
        ofdl357.out --> ofdl358.in;
        ofdl311.out --> ofdl312.in;
        ofdl266.out --> ofdl267.in;
        ofdl282.out --> ofdl283.in;
        ofdl491.out --> ofdl492.in;
        ofdl440.out --> oswitch58.in[0];
        ofdl329.out --> ofdl330.in;
        ofdl313.out --> ofdl314.in;
        ofdl292.out --> ofdl293.in;
        ofdl345.out --> ofdl346.in;
        oswitch47.out[0] --> ofdl364.in;
        oswitch47.out[1] --> ocombiner11.in[1];
        ofdl252.out --> ofdl253.in;
        ofdl270.out --> ocombiner8.in[0];
        ofdl315.out --> ofdl316.in;
        ofdl443.out --> ofdl444.in;
        ofdl377.out --> ofdl378.in;
        ofdl398.out --> ofdl399.in;
        ofdl419.out --> ofdl420.in;
        ofdl476.out --> ofdl477.in;
        ofdl316.out --> oswitch42.in[0];
        ofdl385.out --> ofdl386.in;
        oswitch63.out[0] --> ofdl488.in;
        oswitch63.out[1] --> ocombiner15.in[1];
        oswitch53.out[0] --> ofdl406.in;
        oswitch53.out[1] --> oswitch54.in[1];
        ofdl410.out --> ofdl411.in;
        ofdl474.out --> ofdl475.in;
        ofdl356.out --> ofdl357.in;
        ofdl304.out --> ofdl305.in;
        ofdl348.out --> ofdl349.in;
        ofdl424.out --> ofdl425.in;
        ofdl402.out --> ofdl387.in;
        ofdl441.out --> ofdl442.in;
        ofdl405.out --> oswitch53.in[0];
        ofdl277.out --> ofdl278.in;
        ofdl415.out --> ofdl416.in;
        ofdl278.out --> ofdl263.in;
        ofdl297.out --> ofdl298.in;
        ofdl473.out --> ofdl474.in;
        ofdl294.out --> ofdl295.in;
        ofdl395.out --> ofdl396.in;
        ofdl461.out --> ofdl462.in;
        ofdl318.out --> ofdl319.in;
        ofdl433.out --> ofdl418.in;
        ofdl299.out --> ofdl300.in;
        ofdl249.out --> ofdl250.in;
        ofdl253.out --> ofdl254.in;
        ofdl257.out --> ofdl258.in;
        ofdl429.out --> ofdl430.in;
        ofdl353.out --> ofdl354.in;
        ofdl399.out --> ofdl400.in;
        ofdl490.out --> ofdl491.in;
        ofdl478.out --> ofdl479.in;
        ofdl425.out --> ocombiner13.in[0];
        ofdl481.out --> ofdl482.in;
        ofdl471.out --> oswitch62.in[0];
        oswitch50.out[0] --> ofdl379.in;
        oswitch50.out[1] --> oswitch51.in[1];
        ofdl432.out --> ofdl433.in;
        ofdl449.out --> ofdl450.in;
        ofdl339.out --> ofdl340.in;
        ofdl414.out --> ofdl415.in;
        oswitch62.out[0] --> ofdl472.in;
        oswitch62.out[1] --> oswitch63.in[1];
        ofdl423.out --> ofdl424.in;
        ofdl422.out --> ofdl423.in;
        ofdl495.out --> ofdl480.in;
        ofdl363.out --> ocombiner11.in[0];
        ofdl493.out --> ofdl494.in;
        oswitch43.out[0] --> ofdl333.in;
        oswitch43.out[1] --> ocombiner10.in[1];
        oswitch40.out[0] --> ofdl311.in;
        oswitch40.out[1] --> oswitch41.in[1];
        ofdl271.out --> ofdl272.in;
        ofdl394.out --> ocombiner12.in[0];
        ofdl456.out --> ocombiner14.in[0];
        ofdl457.out --> ofdl458.in;
        ofdl376.out --> ofdl377.in;
        ofdl288.out --> ofdl289.in;
        ofdl285.out --> oswitch38.in[0];
        ofdl406.out --> ofdl407.in;
        ofdl451.out --> ofdl452.in;
        ofdl480.out --> ofdl481.in;
        ofdl386.out --> oswitch51.in[0];
        oswitch38.out[0] --> ofdl286.in;
        oswitch38.out[1] --> oswitch39.in[1];
        ofdl412.out --> ofdl413.in;
        ofdl281.out --> oswitch37.in[0];
        ofdl341.out --> oswitch44.in[0];
        ofdl477.out --> ofdl478.in;
        ofdl427.out --> ofdl428.in;
        ofdl400.out --> ofdl401.in;
}
