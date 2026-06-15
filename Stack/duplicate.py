# str = list('(a+b)+((a))')
# stack = []
# duplicate = False
# for i in range(len(str)):
#     if str[i]==')':
#         hasOperator = False
#         while stack[-1]!='(':
#             top = stack.pop()
#             if top.isalpha() or top in ['+','-','*','/']:
#                 hasOperator = True
#         stack.pop()
#         if not hasOperator:
#             duplicate = True
#             break
#     else:
#         stack.append(str[i])
# print(duplicate)
    
str = list('(a+b)+((a))')
stack = []
duplicate = False
for i in range(len(str)):
    if str[i]==')':
        if stack[-1]=='(':
            duplicate=True
            break
        while stack[-1]!="(":
            stack.pop()
        stack.pop()
        
    else:
        stack.append(str[i])
print(duplicate)
    