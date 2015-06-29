using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.DesignPattern
{
    /// <summary>
    /// The observer design pattern subject,
    /// it provides subcribe/register function for observers.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    class ObserverSubject<T> : System.IObservable<T>
    {
        private List<IObserver<T>> m_observerList;

        public ObserverSubject()
        {
            this.m_observerList = new List<System.IObserver<T>>();
        }

        public System.IDisposable Subscribe(System.IObserver<T> observer)
        {
            if (!m_observerList.Contains(observer))
            {
                m_observerList.Add(observer);
            }

            return new Unsubscriber(m_observerList, observer);
        }

        public void update(T obj)
        {
            foreach (var ob in m_observerList)
            {
                if (obj != null)
                {
                    ob.OnNext(obj);
                }
                else
                {
                    ob.OnError(new Exception("Unkonw values"));
                }
            }
        }

        public void complete()
        {
            foreach (var ob in m_observerList)
            {
                ob.OnCompleted();
            }
        }

        /// <summary>
        /// Inner class cannot access outer class member,
        /// so it has to pass the List object.
        /// </summary>
        private class Unsubscriber : System.IDisposable
        {
            private List<IObserver<T>> _observerList;
            private IObserver<T> _observer;

            public Unsubscriber(List<IObserver<T>> obs, IObserver<T> ob)
            {
                this._observerList = obs;
                this._observer = ob;
            }

            public void Dispose()
            {
                if (_observer != null && _observerList.Contains(_observer))
                {
                    _observerList.Remove(_observer);
                }
            }
        }
    }

    public class Observer<T> : IObserver<T>
    {
        private string m_name;
        private IDisposable unsubscriber;

        public void Subscribe(IObservable<T> provider)
        {
            this.unsubscriber = provider.Subscribe(this);
        }

        public void Unsubscribe()
        {
            this.unsubscriber.Dispose();
        }

        public Observer(string name)
        {
            this.m_name = name;
        }

        public void OnCompleted()
        {
            Console.WriteLine("Done.");
        }

        public void OnError(System.Exception error)
        {
            throw new System.NotImplementedException();
        }

        public void OnNext(T value)
        {
            Console.WriteLine(m_name + " changed to value: " + value);
        }
    }
}

#if false
    static void Main()
    {
        var provider = new ObserverSubject<int>();
        var reporter1 = new Observer<int>("report1");
        var reporter2 = new Observer<int>("report2");

        reporter1.Subscribe(provider);
        reporter2.Subscribe(provider);

        provider.update(2);

        reporter1.Unsubscribe();
        provider.update(4);

        reporter1.Subscribe(provider);

        provider.update(5);
    }
#endif 