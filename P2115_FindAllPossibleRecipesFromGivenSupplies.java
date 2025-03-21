/* 
Problem ID : 2115 

Problem : Find All Possible Recipes from Given Supplies

Statement : You have information about n different recipes. You are given a string array recipes and a 2D 
string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the 
needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, 
i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you 
have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.
*/

/* Problem Link
https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21
*/

class Solution {
    private Set<String> availableSupplies;
    private Map<String, List<String>> recipeToIngredients;
    private Map<String, Integer> visited;
    private List<String> result;

    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        availableSupplies = new HashSet<>(Arrays.asList(supplies));
        recipeToIngredients = new HashMap<>();
        visited = new HashMap<>();
        result = new ArrayList<>();

        for (int i = 0; i < recipes.length; i++) {
            recipeToIngredients.put(recipes[i], ingredients.get(i));
        }

        for (String recipe : recipes) {
            canMake(recipe);
        }

        return result;
    }

    private boolean canMake(String recipe) {
        if (visited.containsKey(recipe)) {
            return visited.get(recipe) == 1;
        }

        if (availableSupplies.contains(recipe)) {
            return true;
        }

        if (!recipeToIngredients.containsKey(recipe)) {
            return false;
        }

        visited.put(recipe, 0);

        for (String ingredient : recipeToIngredients.get(recipe)) {
            if (!canMake(ingredient)) {
                visited.put(recipe, -1);
                return false;
            }
        }

        visited.put(recipe, 1);
        result.add(recipe);
        return true;
    }
}