#include "../../Source/SOLID/SingleResponsibility.h"
#include <gtest/gtest.h>

/*
 * Single Responsibility Principle (SRP)
 * A class should have a single reason to change:
 * a class should have a primary responsibility and it should not take other responsibilities
 */

TEST(SOLIDSingleResponsibility, JournalTest)
{
    Journal journal{ "Dear Diary" };
    journal.addEntry("I ate an apple");
    journal.addEntry("I smiled today");

    std::string titleExpected { "Dear Diary" };
    std::vector<string> entriesExpected { "1: I ate an apple", "2: I smiled today" };

    EXPECT_EQ(journal.getTitle(), titleExpected);
    EXPECT_EQ(journal.getEntries(), entriesExpected);
}

TEST(SOLIDSingleResponsibility, PersistenceManagerTest)
{
    Journal journal{ "Dear Diary" };
    journal.addEntry("I ate an apple");
    journal.addEntry("I smiled today");

    std::string titleExpected{ "Dear Diary" };
    std::vector<string> entriesExpected{ "1: I ate an apple", "2: I smiled today" };

    PersistenceManager pm;
    pm.save(journal, "diary.txt");

    std::ifstream JournalInput("diary.txt");
    std::vector<std::string> JournalEntries;
    bool bIsOpenedFile = false;

    if (JournalInput.is_open())
    {        
        bIsOpenedFile = true;
        std::string JournalEntry;
        while (std::getline(JournalInput, JournalEntry))
        {
            JournalEntries.push_back(JournalEntry);
        }
    }

    EXPECT_EQ(JournalEntries, entriesExpected);
    EXPECT_EQ(bIsOpenedFile, true);
}

