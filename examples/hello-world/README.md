# Hello World sample

## The idea of this sample is to show how to build and deploy a simple smart contract project.

### Requirements
- docker, installed and configured to run without sudo
- make
- Your WAX account and its private key (to deploy the contract)

### Build and deploy

For building and testing the contract you are going to use the *make* utility. The syntax is:

```
$ make [ build |

         clean |
         
         test CONTRACT_ACCOUNT=<the account used to deploy the contract> ]
```

#### Notes:
- The building process uses our [development image](https://hub.docker.com/r/waxteam/dev) from docker hub.
- Be aware that you need:
  - to build your contract first in order to deploy it.
  - to deploy your contract first in order to test it.
- NODEOS_URL parameter is the only one that is optional, its default value is the mainnet deployment address  https://chain.wax.io/

#### Example:
```
# To do this example, you will need a WAX Blockchain account and know your private key for it.
# Create one at https://account.wax.io/
# Note: You will need sufficient WAX on your account to buy 32 KB of RAM and to stake 1 WAX toward
# CPU and NET for your contract's account creation.

# Download the code
git clone https://github.com/worldwide-asset-exchange/wax-cdt.git
cd wax-cdt/examples/hello-world

# Build the smart contract
make build

# Test your deployed smart contract
make test CONTRACT_ACCOUNT=foo
```
