
using System;

using System.Runtime.InteropServices;

namespace something {
    //this class will contain the basic functions
    
    class Program {

        
        [DllImport("../obj/expTester.so", EntryPoint="vxStdWrite")]
        static extern int vxStdWrite(string stringMess);
        static void Main(string[] args) {
            int[] array = new int[10];
            ArrayParam(ref array);

            if(array[0] == 1) {
                vxStdWrite("ArrayParam works");
            } else {
                Console.WriteLine("ArrayParam failed");
            }
        }

        //this method will be used to be passed an array of ints
        static void ArrayParam(ref int[] array) {
            array[0] = 1;
        }
    }
}
