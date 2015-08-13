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

    /// <summary>
    /// Thread safe singleton example
    /// </summary>
    public sealed class Singleton
    {
        private static volatile Singleton instance;
        private static System.Threading.Mutex mutex = new System.Threading.Mutex();

        private Singleton() { }

        public static Singleton Instance
        {
            get
            {
                if (instance == null)
                {
                    mutex.WaitOne();
                    if (instance == null)
                        instance = new Singleton();
                    mutex.ReleaseMutex();
                }

                return instance;
            }
        }
    }

}
