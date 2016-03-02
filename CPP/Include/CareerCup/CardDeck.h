#pragma once
#include "stdafx.h"

// design and implement a general poker card deck.
namespace careercup
{
    enum Type
    {
        Club = 0,
        Diamond = 1,
        Heart = 2,
        Spade = 3
    };

    class Card
    {
    public:
        Card(int value, Type type)
            :m_value(value), m_cardType(type)
        {
        }

        // return the card value, 11 for "J", 12 for "Q", 1 for "A".
        int getValue()
        {
            return m_value;
        }

        // get the card type 
        Type getType()
        {
            return m_cardType;
        }

        //// check if this card is available 
        //bool isAvailable()
        //{
        //    return m_available;
        //}

        //void setAvailable()
        //{
        //    m_available = true;
        //}
    private:
        const Type m_cardType;
        const int m_value;
        //bool m_available;
    };

    template<typename T>
    class CardDeck
    {
    public:
        CardDeck()
        {}

        void shuffle()
        {

        }

        T& getCard()
        {
            m_isAvailable[m_index] = false;
            T& card = m_totalCards[m_index];
            m_index++;

            return card;
        }

        int cardRemains()
        {
            return m_totalCards.size() - m_index;
        }
    private:
        vector<T>       m_totalCards;
        vector<bool>    m_isAvailable;
        int             m_index;
    };

}