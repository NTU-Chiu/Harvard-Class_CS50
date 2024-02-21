# # list_dic = []
# # for i in range(3):
# #     my_dictionary = {}
# #     my_dictionary["symbol"] = "nflx"
# #     my_dictionary["price"] = 345
# #     my_dictionary["number"] = 2
# #     my_dictionary["stock_value"] = 670
# #     list_dic.append(my_dictionary)
# # print(list_dic[0]["symbol"] )
from helpers import apology, login_required, lookup, usd
from cs50 import SQL
db = SQL("sqlite:///finance.db")
# # total_property_value = 0
# # results = db.execute("SELECT * FROM history")
# # print(results)
# # results = db.execute("SELECT * FROM users")
# # results = (db.execute("""SELECT symbol, SUM(shares) FROM history 
# #                      WHERE user_id = 3 AND transaction_type = ? GROUP BY symbol""", 'buy'))
# # for i in range(len(results)):
# #         results[i]["price"] = (lookup(results[i]["symbol"]))["price"]
# #         results[i]["number"] = results[i]["SUM(shares)"]
# #         results[i]["stock_value"] = results[i]["price"] * results[i]["number"] 
# #         total_property_value = total_property_value + results[i]["stock_value"]

# # total_property_value = total_property_value + db.execute("SELECT cash FROM users WHERE id = 3")[0]["cash"]
# # print(results)
# # print(total_property_value)
# # db.execute("""INSERT INTO history (user_id, symbol, price, shares, time, transaction_type, cash_before, cash_after) 
# #             VALUES (3, 'nflx', 300, 1, DATETIME('now'), "sell", 2790.4799999999996, 2490.4799999999996)""")
# # db.execute("""UPDATE users SET cash = ?
# #                                    WHERE id = ?""",  2490.4799999999996, 3)
# # results = db.execute("SELECT * FROM users")

# results = (db.execute("""SELECT symbol, SUM(shares),transaction_type FROM history 
#                         WHERE user_id = 3
#                         GROUP BY transaction_type, symbol """))

# sort_result = next(( this["SUM(shares)"] for this in results if this["transaction_type"] == "sell" and this["symbol"] == "nflx" ), 0)
# print(results)
# print(sort_result)

# results = (db.execute("""SELECT symbol, SUM(shares) FROM history 
#                     WHERE user_id = ? AND transaction_type = ? GROUP BY symbol""", 3, "buy"))
# results_sell = (db.execute("""SELECT symbol, SUM(shares) FROM history 
#                     WHERE user_id = ? AND transaction_type = ? GROUP BY symbol""", 3, "sell"))
# total_property_value = 0

# for i in range(len(results)):
#     results[i]["price"] = (lookup(results[i]["symbol"]))["price"]
#     # 股票數量=(買-賣)
#     results[i]["number"] = results[i]["SUM(shares)"] - \
#         next(( this["SUM(shares)"] for this in results_sell if this["symbol"].upper() == results[i]["symbol"] ), 0)
#     results[i]["stock_value"] = results[i]["price"] * results[i]["SUM(shares)"]
#     total_property_value = total_property_value + results[i]["stock_value"]
#     print(results[i]["symbol"], results[i]["SUM(shares)"], results[i]["number"])
results = db.execute("SELECT * FROM users WHERE username = ?", "A")
if len(results) != 0:
    print("Duplicate")
print(results)