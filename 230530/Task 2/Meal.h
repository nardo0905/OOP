#ifndef __MEAL_H__
#define __MEAL_H__
#include <string>
#include <vector>

class Meal {

private:

    std::string name;
    std::vector<std::string> ingredientList;
    std::string cuisine;
    std::vector<std::string> categoryList;
    unsigned price; // stotinki

public:

    Meal(const std::string& name, const std::string& cuisine, const unsigned price);

    void addIngredient(const std::string& ingredient);
    void addCategory(const std::string& category);

    const std::string& getMealName() const;
    const std::vector<std::string>& getIngredientList() const;
    const std::vector<std::string>& getCategoryList() const;

    void printIngredientList() const;
    void printCategoryList() const;
    void printMeal() const;

};

#endif // __MEAL_H__