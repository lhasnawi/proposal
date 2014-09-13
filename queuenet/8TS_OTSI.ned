import ned.IdealChannel;
import org.omnetpp.queueing.ControlChannel;
import org.omnetpp.queueing.OFDL;
import org.omnetpp.queueing.Ocombiner;
import org.omnetpp.queueing.Ocontroller;
import org.omnetpp.queueing.Osink;
import org.omnetpp.queueing.Osource;
import org.omnetpp.queueing.Osplitter;
import org.omnetpp.queueing.Oswitch;


//
// TODO documentation
//
network _8TS_OTSI
{
    @display("bgb=2339,1163;bgl=3;bgg=40");
    submodules:
        osplitter111: Osplitter {
            @display("p=461,554;is=n");
        }
        oswitch0: Oswitch {
            @display("p=581,554;is=n");
        }
        ofdl0: OFDL {
            @display("p=522,515;is=n");
        }
        ofdl1: OFDL {
            @display("p=641,515;is=n");
        }
        ofdl2: OFDL {
            @display("p=720,515;is=n");
        }
        oswitch1: Oswitch {
            @display("p=781,554;is=n");
        }
        ofdl3: OFDL {
            @display("p=841,515;is=n");
        }
        ofdl4: OFDL {
            @display("p=920,515;is=n");
        }
        ofdl5: OFDL {
            @display("p=1003,515;is=n");
        }
        ofdl6: OFDL {
            @display("p=1082,515;is=n");
        }
        oswitch2: Oswitch {
            @display("p=1139,554;is=n");
        }
        ofdl7: OFDL {
            @display("p=1201,515;is=n");
        }
        ofdl8: OFDL {
            @display("p=1280,515;is=n");
        }
        ofdl9: OFDL {
            @display("p=1363,515;is=n");
        }
        ofdl10: OFDL {
            @display("p=1442,515;is=n");
        }
        ofdl11: OFDL {
            @display("p=1521,515;is=n");
        }
        ofdl12: OFDL {
            @display("p=1600,515;is=n");
        }
        ofdl13: OFDL {
            @display("p=1683,515;is=n");
        }
        ofdl14: OFDL {
            @display("p=1762,515;is=n");
        }
        ocombiner111: Ocombiner {
            @display("p=1821,554");
        }
        ocombiner112: Ocombiner {
            @display("p=1821,637");
        }
        ofdl15: OFDL {
            @display("p=522,598;is=n");
        }
        ofdl16: OFDL {
            @display("p=641,598;is=n");
        }
        ofdl17: OFDL {
            @display("p=720,598;is=n");
        }
        ofdl18: OFDL {
            @display("p=841,598;is=n");
        }
        ofdl19: OFDL {
            @display("p=920,598;is=n");
        }
        ofdl20: OFDL {
            @display("p=1003,598;is=n");
        }
        ofdl21: OFDL {
            @display("p=1082,598;is=n");
        }
        ofdl22: OFDL {
            @display("p=1201,598;is=n");
        }
        ofdl23: OFDL {
            @display("p=1280,598;is=n");
        }
        ofdl24: OFDL {
            @display("p=1363,598;is=n");
        }
        ofdl25: OFDL {
            @display("p=1442,598;is=n");
        }
        ofdl26: OFDL {
            @display("p=1521,598;is=n");
        }
        ofdl27: OFDL {
            @display("p=1600,598;is=n");
        }
        ofdl28: OFDL {
            @display("p=1683,598;is=n");
        }
        ofdl29: OFDL {
            @display("p=1762,598;is=n");
        }
        osplitter112: Osplitter {
            @display("p=461,637;is=n");
        }
        oswitch3: Oswitch {
            @display("p=581,637;is=n");
        }
        oswitch4: Oswitch {
            @display("p=781,637;is=n");
        }
        oswitch5: Oswitch {
            @display("p=1139,637;is=n");
        }
        ocombiner121: Ocombiner {
            @display("p=1821,715");
        }
        ofdl30: OFDL {
            @display("p=522,676;is=n");
        }
        ofdl31: OFDL {
            @display("p=641,676;is=n");
        }
        ofdl32: OFDL {
            @display("p=720,676;is=n");
        }
        ofdl33: OFDL {
            @display("p=841,676;is=n");
        }
        ofdl34: OFDL {
            @display("p=920,676;is=n");
        }
        ofdl35: OFDL {
            @display("p=1003,676;is=n");
        }
        ofdl36: OFDL {
            @display("p=1082,676;is=n");
        }
        ofdl37: OFDL {
            @display("p=1201,676;is=n");
        }
        ofdl38: OFDL {
            @display("p=1280,676;is=n");
        }
        ofdl39: OFDL {
            @display("p=1363,676;is=n");
        }
        ofdl40: OFDL {
            @display("p=1442,676;is=n");
        }
        ofdl41: OFDL {
            @display("p=1521,676;is=n");
        }
        ofdl42: OFDL {
            @display("p=1600,676;is=n");
        }
        ofdl43: OFDL {
            @display("p=1683,676;is=n");
        }
        ofdl44: OFDL {
            @display("p=1762,676;is=n");
        }
        osplitter121: Osplitter {
            @display("p=461,715;is=n");
        }
        oswitch6: Oswitch {
            @display("p=581,715;is=n");
        }
        oswitch7: Oswitch {
            @display("p=781,715;is=n");
        }
        oswitch8: Oswitch {
            @display("p=1139,715;is=n");
        }
        ocombiner122: Ocombiner {
            @display("p=1821,793");
        }
        ofdl45: OFDL {
            @display("p=522,754;is=n");
        }
        ofdl46: OFDL {
            @display("p=641,754;is=n");
        }
        ofdl47: OFDL {
            @display("p=720,754;is=n");
        }
        ofdl48: OFDL {
            @display("p=841,754;is=n");
        }
        ofdl49: OFDL {
            @display("p=920,754;is=n");
        }
        ofdl50: OFDL {
            @display("p=1003,754;is=n");
        }
        ofdl51: OFDL {
            @display("p=1082,754;is=n");
        }
        ofdl52: OFDL {
            @display("p=1201,754;is=n");
        }
        ofdl53: OFDL {
            @display("p=1280,754;is=n");
        }
        ofdl54: OFDL {
            @display("p=1363,754;is=n");
        }
        ofdl55: OFDL {
            @display("p=1442,754;is=n");
        }
        ofdl56: OFDL {
            @display("p=1521,754;is=n");
        }
        ofdl57: OFDL {
            @display("p=1600,754;is=n");
        }
        ofdl58: OFDL {
            @display("p=1683,754;is=n");
        }
        ofdl59: OFDL {
            @display("p=1762,754;is=n");
        }
        osplitter122: Osplitter {
            @display("p=461,793;is=n");
        }
        oswitch9: Oswitch {
            @display("p=581,793;is=n");
        }
        oswitch10: Oswitch {
            @display("p=781,793;is=n");
        }
        oswitch11: Oswitch {
            @display("p=1139,793;is=n");
        }
        ocombiner211: Ocombiner {
            @display("p=1821,876");
        }
        ofdl60: OFDL {
            @display("p=522,837;is=n");
        }
        ofdl61: OFDL {
            @display("p=641,837;is=n");
        }
        ofdl62: OFDL {
            @display("p=720,837;is=n");
        }
        ofdl63: OFDL {
            @display("p=841,837;is=n");
        }
        ofdl64: OFDL {
            @display("p=920,837;is=n");
        }
        ofdl65: OFDL {
            @display("p=1003,837;is=n");
        }
        ofdl66: OFDL {
            @display("p=1082,837;is=n");
        }
        ofdl67: OFDL {
            @display("p=1201,837;is=n");
        }
        ofdl68: OFDL {
            @display("p=1280,837;is=n");
        }
        ofdl69: OFDL {
            @display("p=1363,837;is=n");
        }
        ofdl70: OFDL {
            @display("p=1442,837;is=n");
        }
        ofdl71: OFDL {
            @display("p=1521,837;is=n");
        }
        ofdl72: OFDL {
            @display("p=1600,837;is=n");
        }
        ofdl73: OFDL {
            @display("p=1683,837;is=n");
        }
        ofdl74: OFDL {
            @display("p=1762,837;is=n");
        }
        osplitter211: Osplitter {
            @display("p=461,876;is=n");
        }
        oswitch12: Oswitch {
            @display("p=581,876;is=n");
        }
        oswitch13: Oswitch {
            @display("p=781,876;is=n");
        }
        oswitch14: Oswitch {
            @display("p=1139,876;is=n");
        }
        ocombiner212: Ocombiner {
            @display("p=1821,954");
        }
        ofdl75: OFDL {
            @display("p=522,915;is=n");
        }
        ofdl76: OFDL {
            @display("p=641,915;is=n");
        }
        ofdl77: OFDL {
            @display("p=720,915;is=n");
        }
        ofdl78: OFDL {
            @display("p=841,915;is=n");
        }
        ofdl79: OFDL {
            @display("p=920,915;is=n");
        }
        ofdl80: OFDL {
            @display("p=1003,915;is=n");
        }
        ofdl81: OFDL {
            @display("p=1082,915;is=n");
        }
        ofdl82: OFDL {
            @display("p=1201,915;is=n");
        }
        ofdl83: OFDL {
            @display("p=1280,915;is=n");
        }
        ofdl84: OFDL {
            @display("p=1363,915;is=n");
        }
        ofdl85: OFDL {
            @display("p=1442,915;is=n");
        }
        ofdl86: OFDL {
            @display("p=1521,915;is=n");
        }
        ofdl87: OFDL {
            @display("p=1600,915;is=n");
        }
        ofdl88: OFDL {
            @display("p=1683,915;is=n");
        }
        ofdl89: OFDL {
            @display("p=1762,915;is=n");
        }
        osplitter212: Osplitter {
            @display("p=461,954;is=n");
        }
        oswitch15: Oswitch {
            @display("p=581,954;is=n");
        }
        oswitch16: Oswitch {
            @display("p=781,954;is=n");
        }
        oswitch17: Oswitch {
            @display("p=1139,954;is=n");
        }
        ocombiner221: Ocombiner {
            @display("p=1821,1037");
        }
        ofdl90: OFDL {
            @display("p=522,998;is=n");
        }
        ofdl91: OFDL {
            @display("p=641,998;is=n");
        }
        ofdl92: OFDL {
            @display("p=720,998;is=n");
        }
        ofdl93: OFDL {
            @display("p=841,998;is=n");
        }
        ofdl94: OFDL {
            @display("p=920,998;is=n");
        }
        ofdl95: OFDL {
            @display("p=1003,998;is=n");
        }
        ofdl96: OFDL {
            @display("p=1082,998;is=n");
        }
        ofdl97: OFDL {
            @display("p=1201,998;is=n");
        }
        ofdl98: OFDL {
            @display("p=1280,998;is=n");
        }
        ofdl99: OFDL {
            @display("p=1363,998;is=n");
        }
        ofdl100: OFDL {
            @display("p=1442,998;is=n");
        }
        ofdl101: OFDL {
            @display("p=1521,998;is=n");
        }
        ofdl102: OFDL {
            @display("p=1600,998;is=n");
        }
        ofdl103: OFDL {
            @display("p=1683,998;is=n");
        }
        ofdl104: OFDL {
            @display("p=1762,998;is=n");
        }
        osplitter221: Osplitter {
            @display("p=461,1037;is=n");
        }
        oswitch18: Oswitch {
            @display("p=581,1037;is=n");
        }
        oswitch19: Oswitch {
            @display("p=781,1037;is=n");
        }
        oswitch20: Oswitch {
            @display("p=1139,1037;is=n");
        }
        ocombiner222: Ocombiner {
            @display("p=1821,1115");
        }
        ofdl105: OFDL {
            @display("p=522,1076;is=n");
        }
        ofdl106: OFDL {
            @display("p=641,1076;is=n");
        }
        ofdl107: OFDL {
            @display("p=720,1076;is=n");
        }
        ofdl108: OFDL {
            @display("p=841,1076;is=n");
        }
        ofdl109: OFDL {
            @display("p=920,1076;is=n");
        }
        ofdl110: OFDL {
            @display("p=1003,1076;is=n");
        }
        ofdl111: OFDL {
            @display("p=1082,1076;is=n");
        }
        ofdl112: OFDL {
            @display("p=1201,1076;is=n");
        }
        ofdl113: OFDL {
            @display("p=1280,1076;is=n");
        }
        ofdl114: OFDL {
            @display("p=1363,1076;is=n");
        }
        ofdl115: OFDL {
            @display("p=1442,1076;is=n");
        }
        ofdl116: OFDL {
            @display("p=1521,1076;is=n");
        }
        ofdl117: OFDL {
            @display("p=1600,1076;is=n");
        }
        ofdl118: OFDL {
            @display("p=1683,1076;is=n");
        }
        ofdl119: OFDL {
            @display("p=1762,1076;is=n");
        }
        osplitter222: Osplitter {
            @display("p=461,1115;is=n");
        }
        oswitch21: Oswitch {
            @display("p=581,1115;is=n");
        }
        oswitch22: Oswitch {
            @display("p=781,1115;is=n");
        }
        oswitch23: Oswitch {
            @display("p=1139,1115;is=n");
        }
        osplitter11: Osplitter {
            @display("p=380,593;is=n");
        }
        osplitter12: Osplitter {
            @display("p=380,754;is=n");
        }
        osplitter21: Osplitter {
            @display("p=380,915;is=n");
        }
        osplitter22: Osplitter {
            @display("p=380,1076;is=n");
        }
        osplitter1: Osplitter {
            @display("p=301,676;is=n");
        }
        osplitter2: Osplitter {
            @display("p=301,993;is=n");
        }
        osplitter0: Osplitter {
            @display("p=181,837;is=n");
        }
        ocombiner11: Ocombiner {
            @display("p=1901,593");
        }
        ocombiner12: Ocombiner {
            @display("p=1901,754");
        }
        ocombiner21: Ocombiner {
            @display("p=1901,915");
        }
        ocombiner22: Ocombiner {
            @display("p=1901,1076");
        }
        ocombiner1: Ocombiner {
            @display("p=1981,676");
        }
        ocombiner2: Ocombiner {
            @display("p=1981,993");
        }
        ocombiner0: Ocombiner {
            @display("p=2100,832");
        }
        osource: Osource {
            @display("p=98,837");
        }
        osink: Osink {
            @display("p=2180,832");
        }
        ocontroller: Ocontroller {
            @display("p=1119,348");
        }
    connections:
        osplitter111.out[0] --> IdealChannel --> ofdl0.in;
        ofdl0.out --> IdealChannel --> oswitch0.in[0];
        osplitter111.out[1] --> IdealChannel --> oswitch0.in[1];
        oswitch0.out[0] --> IdealChannel --> ofdl1.in;
        ofdl1.out --> IdealChannel --> ofdl2.in;
        ofdl2.out --> IdealChannel --> oswitch1.in[0];
        oswitch0.out[1] --> IdealChannel --> oswitch1.in[1];
        oswitch1.out[0] --> IdealChannel --> ofdl3.in;
        ofdl3.out --> IdealChannel --> ofdl4.in;
        ofdl4.out --> IdealChannel --> ofdl5.in;
        ofdl5.out --> IdealChannel --> ofdl6.in;
        ofdl6.out --> IdealChannel --> oswitch2.in[0];
        oswitch1.out[1] --> IdealChannel --> oswitch2.in[1];
        oswitch2.out[0] --> IdealChannel --> ofdl7.in;
        ofdl7.out --> IdealChannel --> ofdl8.in;
        ofdl8.out --> IdealChannel --> ofdl9.in;
        ofdl9.out --> IdealChannel --> ofdl10.in;
        ofdl10.out --> IdealChannel --> ofdl11.in;
        ofdl11.out --> IdealChannel --> ofdl12.in;
        ofdl12.out --> IdealChannel --> ofdl13.in;
        ofdl13.out --> IdealChannel --> ofdl14.in;
        ofdl14.out --> IdealChannel --> ocombiner111.in[0];
        oswitch2.out[1] --> IdealChannel --> ocombiner111.in[1];
        osplitter112.out[0] --> IdealChannel --> ofdl15.in;
        osplitter112.out[1] --> IdealChannel --> oswitch3.in[1];
        ofdl19.out --> IdealChannel --> ofdl20.in;
        ofdl17.out --> IdealChannel --> oswitch4.in[0];
        ofdl15.out --> IdealChannel --> oswitch3.in[0];
        ofdl27.out --> IdealChannel --> ofdl28.in;
        ofdl29.out --> IdealChannel --> ocombiner112.in[0];
        oswitch4.out[0] --> IdealChannel --> ofdl18.in;
        oswitch4.out[1] --> IdealChannel --> oswitch5.in[1];
        oswitch3.out[0] --> IdealChannel --> ofdl16.in;
        oswitch3.out[1] --> IdealChannel --> oswitch4.in[1];
        ofdl16.out --> IdealChannel --> ofdl17.in;
        ofdl23.out --> IdealChannel --> ofdl24.in;
        ofdl22.out --> IdealChannel --> ofdl23.in;
        oswitch5.out[0] --> IdealChannel --> ofdl22.in;
        oswitch5.out[1] --> IdealChannel --> ocombiner112.in[1];
        ofdl24.out --> IdealChannel --> ofdl25.in;
        ofdl18.out --> IdealChannel --> ofdl19.in;
        ofdl25.out --> IdealChannel --> ofdl26.in;
        ofdl28.out --> IdealChannel --> ofdl29.in;
        ofdl26.out --> IdealChannel --> ofdl27.in;
        ofdl21.out --> IdealChannel --> oswitch5.in[0];
        ofdl20.out --> IdealChannel --> ofdl21.in;
        osplitter121.out[0] --> IdealChannel --> ofdl30.in;
        osplitter121.out[1] --> IdealChannel --> oswitch6.in[1];
        ofdl34.out --> IdealChannel --> ofdl35.in;
        ofdl32.out --> IdealChannel --> oswitch7.in[0];
        ofdl30.out --> IdealChannel --> oswitch6.in[0];
        ofdl42.out --> IdealChannel --> ofdl43.in;
        ofdl44.out --> IdealChannel --> ocombiner121.in[0];
        oswitch7.out[0] --> IdealChannel --> ofdl33.in;
        oswitch7.out[1] --> IdealChannel --> oswitch8.in[1];
        oswitch6.out[0] --> IdealChannel --> ofdl31.in;
        oswitch6.out[1] --> IdealChannel --> oswitch7.in[1];
        ofdl31.out --> IdealChannel --> ofdl32.in;
        ofdl38.out --> IdealChannel --> ofdl39.in;
        ofdl37.out --> IdealChannel --> ofdl38.in;
        oswitch8.out[0] --> IdealChannel --> ofdl37.in;
        oswitch8.out[1] --> IdealChannel --> ocombiner121.in[1];
        ofdl39.out --> IdealChannel --> ofdl40.in;
        ofdl33.out --> IdealChannel --> ofdl34.in;
        ofdl40.out --> IdealChannel --> ofdl41.in;
        ofdl43.out --> IdealChannel --> ofdl44.in;
        ofdl41.out --> IdealChannel --> ofdl42.in;
        ofdl36.out --> IdealChannel --> oswitch8.in[0];
        ofdl35.out --> IdealChannel --> ofdl36.in;
        osplitter122.out[0] --> IdealChannel --> ofdl45.in;
        osplitter122.out[1] --> IdealChannel --> oswitch9.in[1];
        ofdl49.out --> IdealChannel --> ofdl50.in;
        ofdl47.out --> IdealChannel --> oswitch10.in[0];
        ofdl45.out --> IdealChannel --> oswitch9.in[0];
        ofdl57.out --> IdealChannel --> ofdl58.in;
        ofdl59.out --> IdealChannel --> ocombiner122.in[0];
        oswitch10.out[0] --> IdealChannel --> ofdl48.in;
        oswitch10.out[1] --> IdealChannel --> oswitch11.in[1];
        oswitch9.out[0] --> IdealChannel --> ofdl46.in;
        oswitch9.out[1] --> IdealChannel --> oswitch10.in[1];
        ofdl46.out --> IdealChannel --> ofdl47.in;
        ofdl53.out --> IdealChannel --> ofdl54.in;
        ofdl52.out --> IdealChannel --> ofdl53.in;
        oswitch11.out[0] --> IdealChannel --> ofdl52.in;
        oswitch11.out[1] --> IdealChannel --> ocombiner122.in[1];
        ofdl54.out --> IdealChannel --> ofdl55.in;
        ofdl48.out --> IdealChannel --> ofdl49.in;
        ofdl55.out --> IdealChannel --> ofdl56.in;
        ofdl58.out --> IdealChannel --> ofdl59.in;
        ofdl56.out --> IdealChannel --> ofdl57.in;
        ofdl51.out --> IdealChannel --> oswitch11.in[0];
        ofdl50.out --> IdealChannel --> ofdl51.in;
        osplitter211.out[0] --> IdealChannel --> ofdl60.in;
        osplitter211.out[1] --> IdealChannel --> oswitch12.in[1];
        ofdl64.out --> IdealChannel --> ofdl65.in;
        ofdl62.out --> IdealChannel --> oswitch13.in[0];
        ofdl60.out --> IdealChannel --> oswitch12.in[0];
        ofdl72.out --> IdealChannel --> ofdl73.in;
        ofdl74.out --> IdealChannel --> ocombiner211.in[0];
        oswitch13.out[0] --> IdealChannel --> ofdl63.in;
        oswitch13.out[1] --> IdealChannel --> oswitch14.in[1];
        oswitch12.out[0] --> IdealChannel --> ofdl61.in;
        oswitch12.out[1] --> IdealChannel --> oswitch13.in[1];
        ofdl61.out --> IdealChannel --> ofdl62.in;
        ofdl68.out --> IdealChannel --> ofdl69.in;
        ofdl67.out --> IdealChannel --> ofdl68.in;
        oswitch14.out[0] --> IdealChannel --> ofdl67.in;
        oswitch14.out[1] --> IdealChannel --> ocombiner211.in[1];
        ofdl69.out --> IdealChannel --> ofdl70.in;
        ofdl63.out --> IdealChannel --> ofdl64.in;
        ofdl70.out --> IdealChannel --> ofdl71.in;
        ofdl73.out --> IdealChannel --> ofdl74.in;
        ofdl71.out --> IdealChannel --> ofdl72.in;
        ofdl66.out --> IdealChannel --> oswitch14.in[0];
        ofdl65.out --> IdealChannel --> ofdl66.in;
        osplitter212.out[0] --> IdealChannel --> ofdl75.in;
        osplitter212.out[1] --> IdealChannel --> oswitch15.in[1];
        ofdl79.out --> IdealChannel --> ofdl80.in;
        ofdl77.out --> IdealChannel --> oswitch16.in[0];
        ofdl75.out --> IdealChannel --> oswitch15.in[0];
        ofdl87.out --> IdealChannel --> ofdl88.in;
        ofdl89.out --> IdealChannel --> ocombiner212.in[0];
        oswitch16.out[0] --> IdealChannel --> ofdl78.in;
        oswitch16.out[1] --> IdealChannel --> oswitch17.in[1];
        oswitch15.out[0] --> IdealChannel --> ofdl76.in;
        oswitch15.out[1] --> IdealChannel --> oswitch16.in[1];
        ofdl76.out --> IdealChannel --> ofdl77.in;
        ofdl83.out --> IdealChannel --> ofdl84.in;
        ofdl82.out --> IdealChannel --> ofdl83.in;
        oswitch17.out[0] --> IdealChannel --> ofdl82.in;
        oswitch17.out[1] --> IdealChannel --> ocombiner212.in[1];
        ofdl84.out --> IdealChannel --> ofdl85.in;
        ofdl78.out --> IdealChannel --> ofdl79.in;
        ofdl85.out --> IdealChannel --> ofdl86.in;
        ofdl88.out --> IdealChannel --> ofdl89.in;
        ofdl86.out --> IdealChannel --> ofdl87.in;
        ofdl81.out --> IdealChannel --> oswitch17.in[0];
        ofdl80.out --> IdealChannel --> ofdl81.in;
        osplitter221.out[0] --> IdealChannel --> ofdl90.in;
        osplitter221.out[1] --> IdealChannel --> oswitch18.in[1];
        ofdl94.out --> IdealChannel --> ofdl95.in;
        ofdl92.out --> IdealChannel --> oswitch19.in[0];
        ofdl90.out --> IdealChannel --> oswitch18.in[0];
        ofdl102.out --> IdealChannel --> ofdl103.in;
        ofdl104.out --> IdealChannel --> ocombiner221.in[0];
        oswitch19.out[0] --> IdealChannel --> ofdl93.in;
        oswitch19.out[1] --> IdealChannel --> oswitch20.in[1];
        oswitch18.out[0] --> IdealChannel --> ofdl91.in;
        oswitch18.out[1] --> IdealChannel --> oswitch19.in[1];
        ofdl91.out --> IdealChannel --> ofdl92.in;
        ofdl98.out --> IdealChannel --> ofdl99.in;
        ofdl97.out --> IdealChannel --> ofdl98.in;
        oswitch20.out[0] --> IdealChannel --> ofdl97.in;
        oswitch20.out[1] --> IdealChannel --> ocombiner221.in[1];
        ofdl99.out --> IdealChannel --> ofdl100.in;
        ofdl93.out --> IdealChannel --> ofdl94.in;
        ofdl100.out --> IdealChannel --> ofdl101.in;
        ofdl103.out --> IdealChannel --> ofdl104.in;
        ofdl101.out --> IdealChannel --> ofdl102.in;
        ofdl96.out --> IdealChannel --> oswitch20.in[0];
        ofdl95.out --> IdealChannel --> ofdl96.in;
        osplitter222.out[0] --> IdealChannel --> ofdl105.in;
        osplitter222.out[1] --> IdealChannel --> oswitch21.in[1];
        ofdl109.out --> IdealChannel --> ofdl110.in;
        ofdl107.out --> IdealChannel --> oswitch22.in[0];
        ofdl105.out --> IdealChannel --> oswitch21.in[0];
        ofdl117.out --> IdealChannel --> ofdl118.in;
        ofdl119.out --> IdealChannel --> ocombiner222.in[0];
        oswitch22.out[0] --> IdealChannel --> ofdl108.in;
        oswitch22.out[1] --> IdealChannel --> oswitch23.in[1];
        oswitch21.out[0] --> IdealChannel --> ofdl106.in;
        oswitch21.out[1] --> IdealChannel --> oswitch22.in[1];
        ofdl106.out --> IdealChannel --> ofdl107.in;
        ofdl113.out --> IdealChannel --> ofdl114.in;
        ofdl112.out --> IdealChannel --> ofdl113.in;
        oswitch23.out[0] --> IdealChannel --> ofdl112.in;
        oswitch23.out[1] --> IdealChannel --> ocombiner222.in[1];
        ofdl114.out --> IdealChannel --> ofdl115.in;
        ofdl108.out --> IdealChannel --> ofdl109.in;
        ofdl115.out --> IdealChannel --> ofdl116.in;
        ofdl118.out --> IdealChannel --> ofdl119.in;
        ofdl116.out --> IdealChannel --> ofdl117.in;
        ofdl111.out --> IdealChannel --> oswitch23.in[0];
        ofdl110.out --> IdealChannel --> ofdl111.in;
        osplitter11.out[0] --> IdealChannel --> osplitter111.in;
        osplitter11.out[1] --> IdealChannel --> osplitter112.in;
        osplitter12.out[0] --> IdealChannel --> osplitter121.in;
        osplitter12.out[1] --> IdealChannel --> osplitter122.in;
        osplitter21.out[0] --> IdealChannel --> osplitter211.in;
        osplitter21.out[1] --> IdealChannel --> osplitter212.in;
        osplitter22.out[0] --> IdealChannel --> osplitter221.in;
        osplitter22.out[1] --> IdealChannel --> osplitter222.in;
        osplitter1.out[0] --> IdealChannel --> osplitter11.in;
        osplitter1.out[1] --> IdealChannel --> osplitter12.in;
        osplitter2.out[0] --> IdealChannel --> osplitter21.in;
        osplitter2.out[1] --> IdealChannel --> osplitter22.in;
        osplitter0.out[0] --> IdealChannel --> osplitter1.in;
        osplitter0.out[1] --> IdealChannel --> osplitter2.in;
        osource.out --> IdealChannel --> osplitter0.in;
        ocombiner111.out --> IdealChannel --> ocombiner11.in[0];
        ocombiner112.out --> IdealChannel --> ocombiner11.in[1];
        ocombiner121.out --> IdealChannel --> ocombiner12.in[0];
        ocombiner122.out --> IdealChannel --> ocombiner12.in[1];
        ocombiner211.out --> IdealChannel --> ocombiner21.in[0];
        ocombiner212.out --> IdealChannel --> ocombiner21.in[1];
        ocombiner221.out --> IdealChannel --> ocombiner22.in[0];
        ocombiner222.out --> IdealChannel --> ocombiner22.in[1];
        ocombiner11.out --> IdealChannel --> ocombiner1.in[0];
        ocombiner12.out --> IdealChannel --> ocombiner1.in[1];
        ocombiner21.out --> IdealChannel --> ocombiner2.in[0];
        ocombiner22.out --> IdealChannel --> ocombiner2.in[1];
        ocombiner1.out --> IdealChannel --> ocombiner0.in[0];
        ocombiner2.out --> IdealChannel --> ocombiner0.in[1];
        ocombiner0.out --> IdealChannel --> osink.in++;


        ofdl0.control <--> ControlChannel <--> ocontroller.control++;
        ofdl1.control <--> ControlChannel <--> ocontroller.control++;
        ofdl2.control <--> ControlChannel <--> ocontroller.control++;
        ofdl3.control <--> ControlChannel <--> ocontroller.control++;
        ofdl4.control <--> ControlChannel <--> ocontroller.control++;
        ofdl5.control <--> ControlChannel <--> ocontroller.control++;
        ofdl6.control <--> ControlChannel <--> ocontroller.control++;
        ofdl7.control <--> ControlChannel <--> ocontroller.control++;
        ofdl8.control <--> ControlChannel <--> ocontroller.control++;
        ofdl9.control <--> ControlChannel <--> ocontroller.control++;
        ofdl10.control <--> ControlChannel <--> ocontroller.control++;
        ofdl11.control <--> ControlChannel <--> ocontroller.control++;
        ofdl12.control <--> ControlChannel <--> ocontroller.control++;
        ofdl13.control <--> ControlChannel <--> ocontroller.control++;
        ofdl14.control <--> ControlChannel <--> ocontroller.control++;
        ofdl15.control <--> ControlChannel <--> ocontroller.control++;
        ofdl16.control <--> ControlChannel <--> ocontroller.control++;
        ofdl17.control <--> ControlChannel <--> ocontroller.control++;
        ofdl18.control <--> ControlChannel <--> ocontroller.control++;
        ofdl19.control <--> ControlChannel <--> ocontroller.control++;
        ofdl20.control <--> ControlChannel <--> ocontroller.control++;
        ofdl21.control <--> ControlChannel <--> ocontroller.control++;
        ofdl22.control <--> ControlChannel <--> ocontroller.control++;
        ofdl23.control <--> ControlChannel <--> ocontroller.control++;
        ofdl24.control <--> ControlChannel <--> ocontroller.control++;
        ofdl25.control <--> ControlChannel <--> ocontroller.control++;
        ofdl26.control <--> ControlChannel <--> ocontroller.control++;
        ofdl27.control <--> ControlChannel <--> ocontroller.control++;
        ofdl28.control <--> ControlChannel <--> ocontroller.control++;
        ofdl29.control <--> ControlChannel <--> ocontroller.control++;
        ofdl30.control <--> ControlChannel <--> ocontroller.control++;
        ofdl31.control <--> ControlChannel <--> ocontroller.control++;
        ofdl32.control <--> ControlChannel <--> ocontroller.control++;
        ofdl33.control <--> ControlChannel <--> ocontroller.control++;
        ofdl34.control <--> ControlChannel <--> ocontroller.control++;
        ofdl35.control <--> ControlChannel <--> ocontroller.control++;
        ofdl36.control <--> ControlChannel <--> ocontroller.control++;
        ofdl37.control <--> ControlChannel <--> ocontroller.control++;
        ofdl38.control <--> ControlChannel <--> ocontroller.control++;
        ofdl39.control <--> ControlChannel <--> ocontroller.control++;
        ofdl40.control <--> ControlChannel <--> ocontroller.control++;
        ofdl41.control <--> ControlChannel <--> ocontroller.control++;
        ofdl42.control <--> ControlChannel <--> ocontroller.control++;
        ofdl43.control <--> ControlChannel <--> ocontroller.control++;
        ofdl44.control <--> ControlChannel <--> ocontroller.control++;
        ofdl45.control <--> ControlChannel <--> ocontroller.control++;
        ofdl46.control <--> ControlChannel <--> ocontroller.control++;
        ofdl47.control <--> ControlChannel <--> ocontroller.control++;
        ofdl48.control <--> ControlChannel <--> ocontroller.control++;
        ofdl49.control <--> ControlChannel <--> ocontroller.control++;
        ofdl50.control <--> ControlChannel <--> ocontroller.control++;
        ofdl51.control <--> ControlChannel <--> ocontroller.control++;
        ofdl52.control <--> ControlChannel <--> ocontroller.control++;
        ofdl53.control <--> ControlChannel <--> ocontroller.control++;
        ofdl54.control <--> ControlChannel <--> ocontroller.control++;
        ofdl55.control <--> ControlChannel <--> ocontroller.control++;
        ofdl56.control <--> ControlChannel <--> ocontroller.control++;
        ofdl57.control <--> ControlChannel <--> ocontroller.control++;
        ofdl58.control <--> ControlChannel <--> ocontroller.control++;
        ofdl59.control <--> ControlChannel <--> ocontroller.control++;
        ofdl60.control <--> ControlChannel <--> ocontroller.control++;
        ofdl61.control <--> ControlChannel <--> ocontroller.control++;
        ofdl62.control <--> ControlChannel <--> ocontroller.control++;
        ofdl63.control <--> ControlChannel <--> ocontroller.control++;
        ofdl64.control <--> ControlChannel <--> ocontroller.control++;
        ofdl65.control <--> ControlChannel <--> ocontroller.control++;
        ofdl66.control <--> ControlChannel <--> ocontroller.control++;
        ofdl67.control <--> ControlChannel <--> ocontroller.control++;
        ofdl68.control <--> ControlChannel <--> ocontroller.control++;
        ofdl69.control <--> ControlChannel <--> ocontroller.control++;
        ofdl70.control <--> ControlChannel <--> ocontroller.control++;
        ofdl71.control <--> ControlChannel <--> ocontroller.control++;
        ofdl72.control <--> ControlChannel <--> ocontroller.control++;
        ofdl73.control <--> ControlChannel <--> ocontroller.control++;
        ofdl74.control <--> ControlChannel <--> ocontroller.control++;
        ofdl75.control <--> ControlChannel <--> ocontroller.control++;
        ofdl76.control <--> ControlChannel <--> ocontroller.control++;
        ofdl77.control <--> ControlChannel <--> ocontroller.control++;
        ofdl78.control <--> ControlChannel <--> ocontroller.control++;
        ofdl79.control <--> ControlChannel <--> ocontroller.control++;
        ofdl80.control <--> ControlChannel <--> ocontroller.control++;
        ofdl81.control <--> ControlChannel <--> ocontroller.control++;
        ofdl82.control <--> ControlChannel <--> ocontroller.control++;
        ofdl83.control <--> ControlChannel <--> ocontroller.control++;
        ofdl84.control <--> ControlChannel <--> ocontroller.control++;
        ofdl85.control <--> ControlChannel <--> ocontroller.control++;
        ofdl86.control <--> ControlChannel <--> ocontroller.control++;
        ofdl87.control <--> ControlChannel <--> ocontroller.control++;
        ofdl88.control <--> ControlChannel <--> ocontroller.control++;
        ofdl89.control <--> ControlChannel <--> ocontroller.control++;
        ofdl105.control <--> ControlChannel <--> ocontroller.control++;
        ofdl106.control <--> ControlChannel <--> ocontroller.control++;
        ofdl107.control <--> ControlChannel <--> ocontroller.control++;
        ofdl108.control <--> ControlChannel <--> ocontroller.control++;
        ofdl109.control <--> ControlChannel <--> ocontroller.control++;
        ofdl110.control <--> ControlChannel <--> ocontroller.control++;
        ofdl111.control <--> ControlChannel <--> ocontroller.control++;
        ofdl112.control <--> ControlChannel <--> ocontroller.control++;
        ofdl113.control <--> ControlChannel <--> ocontroller.control++;
        ofdl114.control <--> ControlChannel <--> ocontroller.control++;
        ofdl115.control <--> ControlChannel <--> ocontroller.control++;
        ofdl116.control <--> ControlChannel <--> ocontroller.control++;
        ofdl117.control <--> ControlChannel <--> ocontroller.control++;
        ofdl118.control <--> ControlChannel <--> ocontroller.control++;
        ofdl119.control <--> ControlChannel <--> ocontroller.control++;
        ofdl90.control <--> ControlChannel <--> ocontroller.control++;
        ofdl91.control <--> ControlChannel <--> ocontroller.control++;
        ofdl92.control <--> ControlChannel <--> ocontroller.control++;
        ofdl93.control <--> ControlChannel <--> ocontroller.control++;
        ofdl94.control <--> ControlChannel <--> ocontroller.control++;
        ofdl95.control <--> ControlChannel <--> ocontroller.control++;
        ofdl96.control <--> ControlChannel <--> ocontroller.control++;
        ofdl97.control <--> ControlChannel <--> ocontroller.control++;
        ofdl98.control <--> ControlChannel <--> ocontroller.control++;
        ofdl99.control <--> ControlChannel <--> ocontroller.control++;
        ofdl100.control <--> ControlChannel <--> ocontroller.control++;
        ofdl101.control <--> ControlChannel <--> ocontroller.control++;
        ofdl102.control <--> ControlChannel <--> ocontroller.control++;
        ofdl103.control <--> ControlChannel <--> ocontroller.control++;
        ofdl104.control <--> ControlChannel <--> ocontroller.control++;

        osplitter222.control <--> ControlChannel <--> ocontroller.control++;
        osplitter111.control <--> ControlChannel <--> ocontroller.control++;
        osplitter11.control <--> ControlChannel <--> ocontroller.control++;
        osplitter112.control <--> ControlChannel <--> ocontroller.control++;
        osplitter1.control <--> ControlChannel <--> ocontroller.control++;
        osplitter121.control <--> ControlChannel <--> ocontroller.control++;
        osplitter12.control <--> ControlChannel <--> ocontroller.control++;
        osplitter122.control <--> ControlChannel <--> ocontroller.control++;
        osplitter0.control <--> ControlChannel <--> ocontroller.control++;
        osplitter21.control <--> ControlChannel <--> ocontroller.control++;
        osplitter2.control <--> ControlChannel <--> ocontroller.control++;
        osplitter22.control <--> ControlChannel <--> ocontroller.control++;
        osplitter211.control <--> ControlChannel <--> ocontroller.control++;
        osplitter212.control <--> ControlChannel <--> ocontroller.control++;
        osplitter221.control <--> ControlChannel <--> ocontroller.control++;


        oswitch0.control <--> ControlChannel <--> ocontroller.control++;
        oswitch1.control <--> ControlChannel <--> ocontroller.control++;
        oswitch2.control <--> ControlChannel <--> ocontroller.control++;
        oswitch3.control <--> ControlChannel <--> ocontroller.control++;
        oswitch4.control <--> ControlChannel <--> ocontroller.control++;
        oswitch5.control <--> ControlChannel <--> ocontroller.control++;
        oswitch6.control <--> ControlChannel <--> ocontroller.control++;
        oswitch7.control <--> ControlChannel <--> ocontroller.control++;
        oswitch8.control <--> ControlChannel <--> ocontroller.control++;
        oswitch11.control <--> ControlChannel <--> ocontroller.control++;
        oswitch10.control <--> ControlChannel <--> ocontroller.control++;
        oswitch9.control <--> ControlChannel <--> ocontroller.control++;
        oswitch12.control <--> ControlChannel <--> ocontroller.control++;
        oswitch13.control <--> ControlChannel <--> ocontroller.control++;
        oswitch14.control <--> ControlChannel <--> ocontroller.control++;
        oswitch17.control <--> ControlChannel <--> ocontroller.control++;
        oswitch16.control <--> ControlChannel <--> ocontroller.control++;
        oswitch15.control <--> ControlChannel <--> ocontroller.control++;
        oswitch20.control <--> ControlChannel <--> ocontroller.control++;
        oswitch19.control <--> ControlChannel <--> ocontroller.control++;
        oswitch18.control <--> ControlChannel <--> ocontroller.control++;
        oswitch23.control <--> ControlChannel <--> ocontroller.control++;
        oswitch22.control <--> ControlChannel <--> ocontroller.control++;
        oswitch21.control <--> ControlChannel <--> ocontroller.control++;


        ocombiner111.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner11.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner112.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner121.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner1.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner12.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner122.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner0.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner211.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner21.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner212.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner2.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner221.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner22.control <--> ControlChannel <--> ocontroller.control++;
        ocombiner222.control <--> ControlChannel <--> ocontroller.control++;



        osource.control <--> ControlChannel <--> ocontroller.control++;



        osink.control <--> ControlChannel <--> ocontroller.control++;










}

