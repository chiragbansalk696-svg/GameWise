
#include <stdio.h>
#include <string.h>

int main()
{
    char gameNames[20][40] = {
        "God of War 2018",
        "Red Dead Redemption 2",
        "Cyberpunk 2077",
        "Forza Horizon 5",
        "Hades",
        "Hollow Knight",
        "Minecraft",
        "Elden Ring",
        "GTA V",
        "The Witcher 3",
        "Marvel Spider Man",
        "Ghost of Tsushima",
        "Sekiro",
        "Resident Evil 4",
        "Doom Eternal",
        "Assassins Creed Valhalla",
        "Stardew Valley",
        "Celeste",
        "Cuphead",
        "Terraria"
    };

    char genres[20][20] = {
        "Action", "Adventure", "RPG", "Racing", "Roguelike",
        "Platformer", "Sandbox", "RPG", "Action", "RPG",
        "Action", "Action", "Action", "Horror", "Action",
        "Adventure", "Simulation", "Platformer", "Platformer", "Sandbox"
    };

    char platforms[20][20] = {
        "PC", "PC", "PC", "PC", "PC",
        "PC", "PC", "PC", "PC", "PC",
        "PC", "PC", "PC", "PC", "PC",
        "PC", "PC", "PC", "PC", "PC"
    };

    int prices[20] = {
        1299, 1499, 1999, 999, 599,
        499, 899, 2499, 999, 799,
        1999, 2499, 2499, 1799, 999,
        1499, 399, 499, 699, 399
    };

    int wishlist[20] = {0};
    int collection[20] = {0};

    int goalGame[10] = {0};
    int goalTarget[10] = {0};
    int goalSaved[10] = {0};

    int milestone25[10] = {0};
    int milestone50[10] = {0};
    int milestone75[10] = {0};
    int milestone100[10] = {0};

    int goalCount = 0;
    int xp = 0;

    int choice, i, j;
    int gameChoice, amount;
    int budget, found, score;
    int totalSaved = 0;
    int loaded = 1;

    char preferredGenre[20];
    char preferredPlatform[20];

    FILE *fp;

    /* LOAD PREVIOUS DATA */

    fp = fopen("gamewise.dat", "rb");

    if (fp != NULL)
    {
        if (fread(&goalCount, sizeof(int), 1, fp) != 1 ||
            fread(&xp, sizeof(int), 1, fp) != 1 ||
            fread(wishlist, sizeof(wishlist), 1, fp) != 1 ||
            fread(collection, sizeof(collection), 1, fp) != 1 ||
            fread(goalGame, sizeof(goalGame), 1, fp) != 1 ||
            fread(goalTarget, sizeof(goalTarget), 1, fp) != 1 ||
            fread(goalSaved, sizeof(goalSaved), 1, fp) != 1 ||
            fread(milestone25, sizeof(milestone25), 1, fp) != 1 ||
            fread(milestone50, sizeof(milestone50), 1, fp) != 1 ||
            fread(milestone75, sizeof(milestone75), 1, fp) != 1 ||
            fread(milestone100, sizeof(milestone100), 1, fp) != 1)
        {
            loaded = 0;
        }

        fclose(fp);
    }

    if (loaded == 0 || goalCount < 0 || goalCount > 10 || xp < 0)
    {
        goalCount = 0;
        xp = 0;

        for (i = 0; i < 20; i++)
        {
            wishlist[i] = 0;
            collection[i] = 0;
        }

        for (i = 0; i < 10; i++)
        {
            goalGame[i] = 0;
            goalTarget[i] = 0;
            goalSaved[i] = 0;

            milestone25[i] = 0;
            milestone50[i] = 0;
            milestone75[i] = 0;
            milestone100[i] = 0;
        }
    }

    printf("====================================\n");
    printf("          WELCOME TO GAMEWISE\n");
    printf("   Your Personal Gaming Companion\n");
    printf("====================================\n");

    if (loaded == 1 && goalCount >= 0)
    {
        printf("\nPrevious progress loaded successfully!\n");
    }
    else
    {
        printf("\nStarting a new GameWise profile.\n");
    }

    do
    {
        printf("\n============== MAIN MENU ==============\n");
        printf("1. Browse Game Catalogue\n");
        printf("2. Get Game Recommendations\n");
        printf("3. Manage Wishlist\n");
        printf("4. Manage My Collection\n");
        printf("5. Create Savings Goal\n");
        printf("6. Add Money to Savings Goal\n");
        printf("7. View Dashboard and XP\n");
        printf("8. Exit\n");
        printf("=======================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\n----------- GAME CATALOGUE -----------\n");

                for (i = 0; i < 20; i++)
                {
                    printf("%d. %s | %s | %s | Rs.%d\n",
                           i + 1, gameNames[i], genres[i],
                           platforms[i], prices[i]);
                }
                break;

            case 2:
                printf("\n-------- GAME RECOMMENDATIONS --------\n");

                printf("Available genres:\n");
                printf("Action, Adventure, RPG, Racing,\n");
                printf("Roguelike, Platformer, Sandbox,\n");
                printf("Horror, Simulation\n");

                printf("Enter preferred genre (or Any): ");
                scanf("%19s", preferredGenre);

                printf("Enter preferred platform (PC or Any): ");
                scanf("%19s", preferredPlatform);

                printf("Enter your maximum budget (Rs.): ");
                scanf("%d", &budget);

                found = 0;

                printf("\nRecommended Games:\n");

                for (i = 0; i < 20; i++)
                {
                    score = 0;

                    if (strcmp(preferredGenre, "Any") == 0 ||
                        strcmp(preferredGenre, genres[i]) == 0)
                    {
                        score += 40;
                    }
                    else
                    {
                        continue;
                    }

                    if (strcmp(preferredPlatform, "Any") == 0 ||
                        strcmp(preferredPlatform, platforms[i]) == 0)
                    {
                        score += 20;
                    }
                    else
                    {
                        continue;
                    }

                    if (prices[i] <= budget)
                    {
                        score += 40;
                    }
                    else
                    {
                        continue;
                    }

                    printf("%s | Rs.%d | Match Score: %d/100\n",
                           gameNames[i], prices[i], score);

                    found = 1;
                }

                if (found == 0)
                {
                    printf("No matching games found. Try changing your filters.\n");
                }
                break;

            case 3:
                printf("\n-------------- WISHLIST --------------\n");

                printf("1. Add a game\n");
                printf("2. View wishlist\n");
                printf("Enter choice: ");
                scanf("%d", &j);

                if (j == 1)
                {
                    for (i = 0; i < 20; i++)
                    {
                        printf("%d. %s\n", i + 1, gameNames[i]);
                    }

                    printf("Enter game number: ");
                    scanf("%d", &gameChoice);

                    if (gameChoice >= 1 && gameChoice <= 20)
                    {
                        if (wishlist[gameChoice - 1] == 0)
                        {
                            wishlist[gameChoice - 1] = 1;
                            printf("Game added to wishlist!\n");
                        }
                        else
                        {
                            printf("Game is already in your wishlist.\n");
                        }
                    }
                    else
                    {
                        printf("Invalid game number.\n");
                    }
                }
                else if (j == 2)
                {
                    found = 0;

                    for (i = 0; i < 20; i++)
                    {
                        if (wishlist[i] == 1)
                        {
                            printf("%s - Rs.%d\n",
                                   gameNames[i], prices[i]);
                            found = 1;
                        }
                    }

                    if (found == 0)
                    {
                        printf("Your wishlist is empty.\n");
                    }
                }
                else
                {
                    printf("Invalid choice.\n");
                }
                break;

            case 4:
                printf("\n----------- MY COLLECTION -----------\n");

                printf("1. Add a game I own\n");
                printf("2. View my collection\n");
                printf("Enter choice: ");
                scanf("%d", &j);

                if (j == 1)
                {
                    for (i = 0; i < 20; i++)
                    {
                        printf("%d. %s\n", i + 1, gameNames[i]);
                    }

                    printf("Enter game number: ");
                    scanf("%d", &gameChoice);

                    if (gameChoice >= 1 && gameChoice <= 20)
                    {
                        if (collection[gameChoice - 1] == 0)
                        {
                            collection[gameChoice - 1] = 1;
                            printf("Game added to your collection!\n");
                            xp += 5;
                            printf("You earned 5 XP!\n");
                        }
                        else
                        {
                            printf("Game is already in your collection.\n");
                        }
                    }
                    else
                    {
                        printf("Invalid game number.\n");
                    }
                }
                else if (j == 2)
                {
                    found = 0;

                    for (i = 0; i < 20; i++)
                    {
                        if (collection[i] == 1)
                        {
                            printf("%s\n", gameNames[i]);
                            found = 1;
                        }
                    }

                    if (found == 0)
                    {
                        printf("Your collection is empty.\n");
                    }
                }
                else
                {
                    printf("Invalid choice.\n");
                }
                break;

            case 5:
                printf("\n----------- CREATE SAVINGS GOAL -----------\n");

                if (goalCount >= 10)
                {
                    printf("Maximum number of savings goals reached.\n");
                    break;
                }

                for (i = 0; i < 20; i++)
                {
                    printf("%d. %s | Rs.%d\n",
                           i + 1, gameNames[i], prices[i]);
                }

                printf("Select a game: ");
                scanf("%d", &gameChoice);

                if (gameChoice < 1 || gameChoice > 20)
                {
                    printf("Invalid game number.\n");
                    break;
                }

                printf("Enter target price for this game: Rs.");
                scanf("%d", &goalTarget[goalCount]);

                printf("Enter amount you have already saved: Rs.");
                scanf("%d", &goalSaved[goalCount]);

                if (goalTarget[goalCount] <= 0 ||
                    goalSaved[goalCount] < 0 ||
                    goalSaved[goalCount] > goalTarget[goalCount])
                {
                    printf("Invalid savings information.\n");
                    break;
                }

                goalGame[goalCount] = gameChoice - 1;

                milestone25[goalCount] = 0;
                milestone50[goalCount] = 0;
                milestone75[goalCount] = 0;
                milestone100[goalCount] = 0;

                xp += 10;
                printf("Savings goal created! You earned 10 XP.\n");

                if (goalSaved[goalCount] * 100 >=
                    goalTarget[goalCount] * 25)
                {
                    milestone25[goalCount] = 1;
                    xp += 25;
                    printf("25%% milestone reached! +25 XP\n");
                }

                if (goalSaved[goalCount] * 100 >=
                    goalTarget[goalCount] * 50)
                {
                    milestone50[goalCount] = 1;
                    xp += 50;
                    printf("50%% milestone reached! +50 XP\n");
                }

                if (goalSaved[goalCount] * 100 >=
                    goalTarget[goalCount] * 75)
                {
                    milestone75[goalCount] = 1;
                    xp += 75;
                    printf("75%% milestone reached! +75 XP\n");
                }

                if (goalSaved[goalCount] == goalTarget[goalCount])
                {
                    milestone100[goalCount] = 1;
                    xp += 150;
                    printf("Goal completed! +150 XP\n");
                }

                goalCount++;
                break;

            case 6:
                printf("\n---------- ADD TO SAVINGS ----------\n");

                if (goalCount == 0)
                {
                    printf("You have not created any savings goals yet.\n");
                    break;
                }

                for (i = 0; i < goalCount; i++)
                {
                    printf("%d. %s | Saved: Rs.%d / Rs.%d\n",
                           i + 1, gameNames[goalGame[i]],
                           goalSaved[i], goalTarget[i]);
                }

                printf("Select a savings goal: ");
                scanf("%d", &gameChoice);

                if (gameChoice < 1 || gameChoice > goalCount)
                {
                    printf("Invalid goal number.\n");
                    break;
                }

                i = gameChoice - 1;

                if (goalSaved[i] == goalTarget[i])
                {
                    printf("This savings goal is already completed!\n");
                    break;
                }

                printf("Enter amount to add: Rs.");
                scanf("%d", &amount);

                if (amount <= 0 ||
                    amount > goalTarget[i] - goalSaved[i])
                {
                    printf("Invalid amount. You can add up to Rs.%d.\n",
                           goalTarget[i] - goalSaved[i]);
                    break;
                }

                goalSaved[i] += amount;

                printf("Savings updated successfully!\n");

                if (milestone25[i] == 0 &&
                    goalSaved[i] * 100 >= goalTarget[i] * 25)
                {
                    milestone25[i] = 1;
                    xp += 25;
                    printf("25%% milestone reached! +25 XP\n");
                }

                if (milestone50[i] == 0 &&
                    goalSaved[i] * 100 >= goalTarget[i] * 50)
                {
                    milestone50[i] = 1;
                    xp += 50;
                    printf("50%% milestone reached! +50 XP\n");
                }

                if (milestone75[i] == 0 &&
                    goalSaved[i] * 100 >= goalTarget[i] * 75)
                {
                    milestone75[i] = 1;
                    xp += 75;
                    printf("75%% milestone reached! +75 XP\n");
                }

                if (milestone100[i] == 0 &&
                    goalSaved[i] == goalTarget[i])
                {
                    milestone100[i] = 1;
                    xp += 150;
                    printf("Congratulations! Savings goal completed!\n");
                    printf("You earned 150 XP!\n");
                }

                printf("Current savings: Rs.%d / Rs.%d\n",
                       goalSaved[i], goalTarget[i]);
                break;

            case 7:
                printf("\n============= GAMEWISE DASHBOARD =============\n");

                printf("Total XP: %d\n", xp);

                if (xp < 100)
                {
                    printf("Level 1 - Beginner\n");
                    printf("Next level at 100 XP.\n");
                }
                else if (xp < 250)
                {
                    printf("Level 2 - Game Explorer\n");
                    printf("Next level at 250 XP.\n");
                }
                else if (xp < 500)
                {
                    printf("Level 3 - Pro Saver\n");
                    printf("Next level at 500 XP.\n");
                }
                else if (xp < 1000)
                {
                    printf("Level 4 - Gaming Strategist\n");
                    printf("Next level at 1000 XP.\n");
                }
                else
                {
                    printf("Level 5 - Legendary Gamer\n");
                    printf("Maximum level reached!\n");
                }

                printf("\n--------- SAVINGS OVERVIEW ---------\n");

                totalSaved = 0;

                for (i = 0; i < goalCount; i++)
                {
                    totalSaved += goalSaved[i];

                    printf("\nGame: %s\n", gameNames[goalGame[i]]);
                    printf("Saved: Rs.%d / Rs.%d\n",
                           goalSaved[i], goalTarget[i]);

                    printf("Remaining: Rs.%d\n",
                           goalTarget[i] - goalSaved[i]);

                    printf("Progress: %d%%\n",
                           goalSaved[i] * 100 / goalTarget[i]);

                    if (goalSaved[i] == goalTarget[i])
                    {
                        printf("Status: COMPLETED\n");
                    }
                    else
                    {
                        printf("Status: IN PROGRESS\n");
                    }
                }

                printf("\nTotal money saved across goals: Rs.%d\n",
                       totalSaved);

                printf("\nWishlist games: ");
                found = 0;

                for (i = 0; i < 20; i++)
                {
                    if (wishlist[i] == 1)
                    {
                        found++;
                    }
                }

                printf("%d\n", found);

                printf("Games in collection: ");
                found = 0;

                for (i = 0; i < 20; i++)
                {
                    if (collection[i] == 1)
                    {
                        found++;
                    }
                }

                printf("%d\n", found);

                printf("==============================================\n");
                break;

            case 8:
                printf("\nThank you for using GameWise!\n");
                printf("Keep gaming. Keep saving. Keep exploring!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        /* SAVE ALL USER DATA */

        fp = fopen("gamewise.dat", "wb");

        if (fp != NULL)
        {
            fwrite(&goalCount, sizeof(int), 1, fp);
            fwrite(&xp, sizeof(int), 1, fp);

            fwrite(wishlist, sizeof(wishlist), 1, fp);
            fwrite(collection, sizeof(collection), 1, fp);

            fwrite(goalGame, sizeof(goalGame), 1, fp);
            fwrite(goalTarget, sizeof(goalTarget), 1, fp);
            fwrite(goalSaved, sizeof(goalSaved), 1, fp);

            fwrite(milestone25, sizeof(milestone25), 1, fp);
            fwrite(milestone50, sizeof(milestone50), 1, fp);
            fwrite(milestone75, sizeof(milestone75), 1, fp);
            fwrite(milestone100, sizeof(milestone100), 1, fp);

            fclose(fp);
        }
        else
        {
            printf("Warning: Could not save your progress!\n");
        }

    } while (choice != 8);

    return 0;
}
