#!/usr/bin/env python
# coding: utf-8

# In[9]:


import snscrape.modules.twitter as sntwitter
import pandas as pd
import networkx as nx
import numpy as np
import re
import matplotlib.pyplot as plt


# In[10]:


tweets_list = []

for i, tweet in enumerate(sntwitter.TwitterSearchScraper('utbk since:2020-1-1 until:2022-9-24').get_items()):
    if i>10000:
        break
    tweets_list.append([tweet.date, tweet.id, tweet.content, tweet.user.username])

tweet_df = pd.DataFrame(tweets_list, columns=['Datetime','Tweet ID', 'Text', 'Username'])
tweet_df


# In[11]:


tweet_df.to_csv('tweet.csv', index=False)


# In[12]:


df = pd.read_csv('./tweet.csv')


# In[13]:


df = df.replace(np.nan, '')


# In[14]:


G_mention = nx.DiGraph()

for r in df.iterrows():
    author = r[1]["Username"]
    author = f'@{author}'

    text = r[1]['Text']

    try:
        timestamp = pd.to_datetime(r[1]['Datetime'])
    except:
        continue

    mentions = set(re.findall(r"@(\w+)", text))

    if len(mentions)>0:
        for u in mentions:
            u = f'@{u}'
            G_mention.add_edge(author,u,Timestamp=timestamp)


# In[15]:


from operator import itemgetter

graph_centrality = nx.degree_centrality(G_mention)
max_de = max(graph_centrality.items(), key=itemgetter(1))
graph_closeness = nx.closeness_centrality(G_mention)
max_clo = max(graph_closeness.items(), key=itemgetter(1))
graph_betweenness = nx.betweenness_centrality(G_mention, normalized=True, endpoints=False)
max_bet = max(graph_betweenness.items(), key=itemgetter(1))

print('centrality measures dari network')
print('Degree centrality:', graph_centrality)
print('Closeness centrality:', graph_closeness)
print('Betweenness centrality:', graph_betweenness)


# In[16]:


df_mention = nx.to_pandas_edgelist(G_mention)
df_mention.to_csv('mention1.csv', index=False)

