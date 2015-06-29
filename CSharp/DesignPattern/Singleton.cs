using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.DesignPattern
{
    class SingletonObject
    {
        public static SingletonObject Instance
        {
            get
            {
                if (m_instance == null)
                    m_instance = new SingletonObject();
                return m_instance;
            }
        }

        private SingletonObject() { }
        private static SingletonObject m_instance;
    }
}
