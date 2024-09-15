#include "lists.h"
#include <stddef.h>  

/**
 * get_middle - finds the middle of the linked list
 * @head: pointer to the head of the list
 * Return: pointer to the middle node
 */
listint_t *get_middle(listint_t *head)
{
    listint_t *slow = head;
    listint_t *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return (slow);
}

/**
 * reverse_list - reverses a linked list
 * @head: pointer to the head of the list
 * Return: pointer to the head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return (prev);
}

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: pointer to the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *middle;
    listint_t *second_half;
    listint_t *second_half_copy;
    listint_t *current = *head;
    int result = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    middle = get_middle(*head);
    second_half = reverse_list(middle->next);
    second_half_copy = second_half;

    while (current != middle->next)
    {
        if (current->n != second_half->n)
        {
            result = 0;
            break;
        }
        current = current->next;
        second_half = second_half->next;
    }

    reverse_list(second_half_copy);

    return (result);
}
