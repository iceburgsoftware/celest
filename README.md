celest
======

The main server code for for the AKS prime project.

Preliminary goals: To break the AKS algorithm up into work blocks that a client side process can 
handle and report back on. To be able to check and verify all results to a high degree of certainty.
To generate new target numbers and do rough checks on them quickly.  Provide fault tolerance, quick recovery, 
and distributable problem solving.

rough outline:
- read configuration file for port and other information
- load data and determine step of algorithm, work blocks done, next work blocks
- open port and start offering work blocks for download
    - provide clients a packet containing algorithm, target number hash and step
    - check clients against a banlist of untrusted clients
    - if they need it, let them download target number
    - provide the work block and target number if needed.
- accept work block completeness and results from clients
    - randomly audit clients either accross network or internally
    - ban unreliable clients
