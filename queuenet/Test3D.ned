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
import org.omnetpp.queueing.Controller3D;
import org.omnetpp.queueing.Switch3D;


//
// TODO documentation
//
network Test3D
{
    @display("bgb=939,660");
    submodules:
        controller3D: Controller3D {
            @display("p=444,91");
        }
        switch3D: Switch3D {
            @display("p=237,266");
        }
        switch3D1: Switch3D {
            @display("p=237,427");
        }
        switch3D2: Switch3D {
            @display("p=452,266");
        }
        switch3D3: Switch3D {
            @display("p=452,421");
        }
        switch3D4: Switch3D {
            @display("p=672,266");
        }
        switch3D5: Switch3D {
            @display("p=672,415");
        }
}

