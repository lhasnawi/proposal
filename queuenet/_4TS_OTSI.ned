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

import org.omnetpp.queueing.ControlChannel;
import org.omnetpp.queueing.OFDL;
import org.omnetpp.queueing.Ocombiner;
import org.omnetpp.queueing.Ocontroller;
import org.omnetpp.queueing.Osink;
import org.omnetpp.queueing.Osource;
import org.omnetpp.queueing.Osplitter;
import org.omnetpp.queueing.Oswitch;


network _4TS_OTSI
{
    @display("bgb=1340,932,white");
    submodules:
        osink: Osink {
            @display("p=1205,587");
        }
        osplitter0: Osplitter {
            @display("p=140,585");
        }
        osplitter1: Osplitter {
            @display("p=223,421");
        }
        osplitter2: Osplitter {
            @display("p=223,751");
        }
        osplitter11: Osplitter {
            @display("p=304,338");
        }
        ofdl111: OFDL {
            @display("p=345,258");
        }
        ofdl121: OFDL {
            @display("p=449,259");
        }
        ofdl122: OFDL {
            @display("p=528,257");
        }
        ofdl141: OFDL {
            @display("p=654,258");
        }
        ofdl142: OFDL {
            @display("p=736,257");
        }
        ofdl143: OFDL {
            @display("p=816,258");
        }
        ofdl144: OFDL {
            @display("p=897,258");
        }
        oswitch10: Oswitch {
            @display("p=386,340");
        }
        oswitch11: Oswitch {
            @display("p=593,339");
        }
        ocombiner11: Ocombiner {
            @display("p=960,339");
        }
        ocombiner1: Ocombiner {
            @display("p=1041,422");
        }
        ocombiner12: Ocombiner {
            @display("p=959,503");
        }
        ofdl211: OFDL {
            @display("p=344,422");
        }
        ofdl221: OFDL {
            @display("p=448,423");
        }
        ofdl222: OFDL {
            @display("p=527,421");
        }
        ofdl241: OFDL {
            @display("p=653,422");
        }
        ofdl242: OFDL {
            @display("p=735,421");
        }
        ofdl243: OFDL {
            @display("p=815,422");
        }
        ofdl244: OFDL {
            @display("p=896,422");
        }
        osplitter12: Osplitter {
            @display("p=303,502");
        }
        oswitch20: Oswitch {
            @display("p=385,504");
        }
        oswitch21: Oswitch {
            @display("p=592,503");
        }
        ocombiner21: Ocombiner {
            @display("p=961,668");
        }
        ofdl311: OFDL {
            @display("p=346,587");
        }
        ofdl321: OFDL {
            @display("p=450,588");
        }
        ofdl322: OFDL {
            @display("p=529,586");
        }
        ofdl341: OFDL {
            @display("p=655,587");
        }
        ofdl342: OFDL {
            @display("p=737,586");
        }
        ofdl343: OFDL {
            @display("p=817,587");
        }
        ofdl344: OFDL {
            @display("p=898,587");
        }
        osplitter21: Osplitter {
            @display("p=305,667");
        }
        oswitch30: Oswitch {
            @display("p=387,669");
        }
        oswitch31: Oswitch {
            @display("p=594,668");
        }
        ocombiner22: Ocombiner {
            @display("p=959,833");
        }
        ofdl411: OFDL {
            @display("p=344,752");
        }
        ofdl421: OFDL {
            @display("p=448,753");
        }
        ofdl422: OFDL {
            @display("p=527,751");
        }
        ofdl441: OFDL {
            @display("p=653,752");
        }
        ofdl442: OFDL {
            @display("p=735,751");
        }
        ofdl443: OFDL {
            @display("p=815,752");
        }
        ofdl444: OFDL {
            @display("p=896,752");
        }
        osplitter22: Osplitter {
            @display("p=303,832");
        }
        oswitch40: Oswitch {
            @display("p=385,834");
        }
        oswitch41: Oswitch {
            @display("p=592,833");
        }
        ocombiner2: Ocombiner {
            @display("p=1043,749");
        }
        ocombiner0: Ocombiner {
            @display("p=1125,586");
        }
        ocontroller: Ocontroller {
            @display("p=618,109");
        }
        osource: Osource {
            @display("p=27,586");
        }
    connections:
        osource.out --> osplitter0.in;
        osplitter11.out[0] --> ofdl111.in;
        ofdl111.out --> oswitch10.in[0];
        oswitch10.out[0] --> ofdl121.in;
        ofdl121.out --> ofdl122.in;
        ofdl122.out --> oswitch11.in[0];
        oswitch11.out[0] --> ofdl141.in;
        ofdl141.out --> ofdl142.in;
        ofdl142.out --> ofdl143.in;
        ofdl143.out --> ofdl144.in;
        ofdl144.out --> ocombiner11.in[0];
        osplitter11.out[1] --> oswitch10.in[1];
        oswitch10.out[1] --> oswitch11.in[1];
        oswitch11.out[1] --> ocombiner11.in[1];
        oswitch20.out[0] --> ofdl221.in;
        oswitch20.out[1] --> oswitch21.in[1];
        osplitter12.out[0] --> ofdl211.in;
        osplitter12.out[1] --> oswitch20.in[1];
        ofdl244.out --> ocombiner12.in[0];
        ofdl221.out --> ofdl222.in;
        ofdl222.out --> oswitch21.in[0];
        ofdl241.out --> ofdl242.in;
        ofdl211.out --> oswitch20.in[0];
        ofdl243.out --> ofdl244.in;
        ofdl242.out --> ofdl243.in;
        oswitch21.out[0] --> ofdl241.in;
        oswitch21.out[1] --> ocombiner12.in[1];
        oswitch30.out[0] --> ofdl321.in;
        oswitch30.out[1] --> oswitch31.in[1];
        osplitter21.out[0] --> ofdl311.in;
        osplitter21.out[1] --> oswitch30.in[1];
        ofdl344.out --> ocombiner21.in[0];
        ofdl321.out --> ofdl322.in;
        ofdl322.out --> oswitch31.in[0];
        ofdl341.out --> ofdl342.in;
        ofdl311.out --> oswitch30.in[0];
        ofdl343.out --> ofdl344.in;
        ofdl342.out --> ofdl343.in;
        oswitch31.out[0] --> ofdl341.in;
        oswitch31.out[1] --> ocombiner21.in[1];
        oswitch40.out[0] --> ofdl421.in;
        oswitch40.out[1] --> oswitch41.in[1];
        osplitter22.out[0] --> ofdl411.in;
        osplitter22.out[1] --> oswitch40.in[1];
        ofdl444.out --> ocombiner22.in[0];
        ofdl421.out --> ofdl422.in;
        ofdl422.out --> oswitch41.in[0];
        ofdl441.out --> ofdl442.in;
        ofdl411.out --> oswitch40.in[0];
        ofdl443.out --> ofdl444.in;
        ofdl442.out --> ofdl443.in;
        oswitch41.out[0] --> ofdl441.in;
        oswitch41.out[1] --> ocombiner22.in[1];
        osplitter1.out[0] --> osplitter11.in;
        osplitter1.out[1] --> osplitter12.in;
        osplitter2.out[0] --> osplitter21.in;
        osplitter2.out[1] --> osplitter22.in;
        osplitter0.out[0] --> osplitter1.in;
        osplitter0.out[1] --> osplitter2.in;
        ocombiner11.out --> ocombiner1.in[0];
        ocombiner12.out --> ocombiner1.in[1];
        ocombiner21.out --> ocombiner2.in[0];
        ocombiner22.out --> ocombiner2.in[1];
        ocombiner1.out --> ocombiner0.in[0];
        ocombiner2.out --> ocombiner0.in[1];
        ocombiner0.out --> osink.in++;
        //Osplitter connection
        osplitter0.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        osplitter1.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        osplitter2.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        osplitter11.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        osplitter12.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        osplitter21.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        osplitter22.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        //Ocombiner Connection 
        ocombiner11.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ocombiner1.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ocombiner12.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ocombiner21.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ocombiner22.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ocombiner2.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ocombiner0.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
		// Oswitch Connections
        oswitch10.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        oswitch11.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        oswitch20.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        oswitch21.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        oswitch30.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        oswitch31.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        oswitch40.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        oswitch41.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        // OFDL Connections    
        ofdl111.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl121.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl122.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl141.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl142.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl143.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl144.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl211.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl221.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl222.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl241.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl242.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl243.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl244.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl311.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl321.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl322.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl341.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl342.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl343.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl344.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl411.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl421.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl422.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl441.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl442.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl443.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        ofdl444.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;
        // Osink Connections      
        osink.control <--> ControlChannel { @display("ls=,00"); } <--> ocontroller.control++;

        ocontroller.control++ <--> ControlChannel { @display("ls=,00"); } <--> osource.control;





}
